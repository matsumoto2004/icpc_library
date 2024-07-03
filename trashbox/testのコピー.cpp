#include <iostream>
#include "stm32f4xx_it.h"
#include "tim.h"
#include "usart.h"
#include "machine.hpp"
#include "wrap.hpp"

//B班

using namespace Machine;
void cycle_callback() {
  update_status();  //消しちゃだめ！!
  
  //この下に記述
  //この後の処理が周期実行される
  //緩和コマンド
  bool soft = false;
  if(isCircle()){
    soft = true;
  }
  if(isTriangle()){
    soft = false;
  }
  //反転コマンド
  bool reverse = false;
  if(isSquare()){
    reverse = true;
  }
  if(isCross()){
    reverse = false;
  }
  
  


  int low=20,high=40;
  //右モーター前進（左に曲がる）
  if(isL1()){
    if(reverse){
      if(soft){
        motor2(-low);motor1(-low / 2);
      }
      else{
        motor2(-high);motor1(-high / 2);
      }
    }
    else if(soft){
      motor1(low); motor2(low / 2);
    }
    else{
      motor1(high); motor2(high / 2);
    }
  }
  //右モーター後進（左に曲がる）
  else if(isL2()){
    //反転中
    if(reverse){
      if(soft){
        motor2(low);motor1(low / 2);
      } 
      else{
        motor2(high);motor1(high / 2);
      }
    }
    //通常
    else if(soft){
      motor1(-low); motor2(-low / 2);
    }
    else{
      motor1(-high); motor2(-high / 2);
    }
  }
  else{
    motor1(0); motor2(0);
  }
  
  //左モーター前進（右に曲がる）
  if(isR1()){
    if(reverse){
      if(soft){
        motor1(-low); motor2(-low / 2);
      }
      else{
        motor1(-high); motor2(-high / 2);
      }

    }
    else if(soft){
      motor2(low);motor1(low / 2);
    }
    else{
      motor2(high);motor1(high / 2);
    }
  }
  //左モーター後進（右に曲がる）
  else if(isR2()){
    if(reverse){
      if(soft){
        motor1(low); motor2(low / 2);
      }
      else{
        motor1(high); motor2(high / 2);
      }
    }
    else if(soft){
      motor2(-low);motor1(-low / 2);
    }
    else{
      motor2(-high);motor1(-high / 2);
    }
  }
  else{
    motor1(0); motor2(0);
  }
  //
  
  
  //お財布側 + 金庫側reverse
  int low2=20,high2=40,aug=60;
  if(isUp()){
    if(reverse){
      servo(aug);
    }
    else if(soft){
      motor3(low2);
    }
    else{
      motor3(high2);
    }
  }
  else if(isDown()){
    if(reverse){
      servo(-aug);
    }
    else if(soft){
      motor3(-low2);
    }
    else{
      motor3(-high2);
    }
  }
  else{
    motor3(0);
  }
  
  //金庫側上下
  /*
  int low3=20,high3=40;
  if(isTriangle()){
    
    if(soft){
      motor4(low3);
    }
    else{
      motor4(high3);
    }
  }
  else if(isCross()){
  
    if(soft){
      motor4(-low3);
    }
    else{
      motor4(-high3);
    }
  }
  else{
    motor4(0);
  }
  
  //金庫側円キャッチ
  
  int low4=30,high4=60;
  if(isSquare()){
    if(soft){
      servo1(-low4);
    }
    else{
      servo1(low4);
    }
  }
  else{
    servo1(0);
  }
  */
  

  //緊急用のstick操作
  /*
  int x=JoypadRX(),y=JoypadRY();
  int mt1=y,mt2=y;
  if(x>0&&y>0){
    mt2-=x/2;
  }
  if(x<0&&y>0){
    mt1-=abs(x/2);
  } 
  if(x>0&&y<0){
    mt1+=x/2;
  }
  if(x<0&&y<0){
    mt2+=abs(x/2);
  }
  motor1(mt1);
  motor2(mt2);
  */

  //金庫側上下を左スティックに適用
  /*
  int x2=JoypadLX(),y2=JoypadLY();
  int mt3 = y2;
  motor3(-mt3);
  */

//ここより下は適当
  /*
  if(x>0&&y>0){
    mt2-=x/2;
  }
  if(x<0&&y>0){
    mt1-=abs(x/2);
  } 
  if(x>0&&y<0){
    mt1+=x/2;
  }
  if(x<0&&y<0){
    mt2+=abs(x/2);
  }
  motor1(mt1);
  motor2(mt2);
  */

  
  //ここまで記述OK
}

//以下 消しちゃダメ
void cycle_callback_start()
{
    HAL_TIM_Base_Start_IT(&htim6);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim == &htim6) { cycle_callback(); }
}