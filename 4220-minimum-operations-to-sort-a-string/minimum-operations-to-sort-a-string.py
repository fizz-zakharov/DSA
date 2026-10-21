class Solution:
    def minOperations(self, s: str) -> int:
        n=len(s)
        if n==2:
            if s[0]>s[1]:
                return -1
            else: 
                return 0
        mx='a'
        mn='z'
        for i in range(n):
            if s[i]>mx:
                mx=s[i]
            if s[i]<mn:
                mn=s[i]
        cmx=0
        cmn=0
        for i in range(n):
            if s[i]==mx:
                cmx+=1
            if s[i]==mn:
                cmn+=1
        temp=list(s)
        srt=sorted(s)
        if(temp==srt):return 0
        if(s[0]==mx and s[-1]==mn and cmx==1 and cmn==1):return 3
        if(s[0]==mn or s[-1]==mx):return 1
        return 2


        