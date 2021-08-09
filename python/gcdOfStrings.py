import math

class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            return ""
        factor_len = math.gcd(len(str1), len(str2))
        factor = str1[:factor_len]
        return factor