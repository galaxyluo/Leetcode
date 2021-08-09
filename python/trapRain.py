class Solution:
    def trap(self, height):
        if height == None:
            return 0
        stack = []
        i = 1
        res = 0
        '''将第一个非零元素入栈
        while height[i] == 0 and i < len(height):
            i += 1
        if i == len(height) - 1:
            return 0
        else:
            stack.append(height[i])
        '''
        stack.append(height[0])
        for i in range(len(height) - 1):
            #小于等于栈顶元素的高度入栈
            if height[i] <= stack[0]:
                stack.append(height[i])
            #大于栈顶元素的，依次出栈计算结果
            else:
                while stack:
                    res += stack[0] - stack[-1]
                    stack.pop()
        return res
