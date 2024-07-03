s = input()
n = len(s)
seen = False
ans = ""
for i in range(n):
    if s[i]=='.':
        ans=""
    else:
        ans+=s[i]
print(ans)