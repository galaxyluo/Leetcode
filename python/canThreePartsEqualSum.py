import time

class Solution:
    '''
    def canThreePartsEqualSum(self, A) -> bool:
        def sum(listPart):
            sumRes = 0
            for i in listPart:
                sumRes += i
            return sumRes
        
        partRes = sum(A) / 3
        if sum(A) % 3 != 0:
            return False
        i = 1
        j = len(A) - 1
        while i < j:
            if sum(A[0:i]) != partRes:
                i += 1
            elif sum(A[j:]) != partRes:
                j -= 1
            elif sum(A[0:i]) == partRes and sum(A[j:]) == partRes and i!= j:
                return True
        
        return False
    '''
    def canThreePartsEqualSum(self, A) -> bool:
        if sum(A) % 3 != 0:
            return False
        avg = sum(A) / 3
        cur = 0
        cnt = 0
        for i in A:
            cur += i
            if cur == avg:
                cnt += 1
                cur = 0
        if cnt >= 3:
            return True
        else: return False    

if __name__ == '__main__':
    A = [18,12,-18,18,-19,-1,10,10]
    ob = Solution()
    print(ob.canThreePartsEqualSum(A))