class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
    	if len(keysPressed) == 0:
    		return
    	tmpChar = keysPressed[0]
    	tmpMax = releaseTimes[0]
    	for i in range(1, len(releaseTimes)):
    		if releaseTimes[i] - releaseTimes[i - 1] > tmpMax:
    			tmpMax = releaseTimes[i] - releaseTimes[i - 1]
    			tmpChar = keysPressed[i]
    		if releaseTimes[i] - releaseTimes[i - 1] == tmpMax:
    			tmpChar = max(keysPressed[i], tmpChar)

    	return tmpChar

