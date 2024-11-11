class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        l = sentence.split()
        n = len(l)
        for i in range(n):
            if l[i][-1] != l[(i+1)%n][0]:
                return False
        return True
        