class Solution:
    def intersecting(self, i1: List[int], i2: List[int]) -> bool:
        return i1[1] >= i2[0] and i2[1] >= i1[0]

    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if len(intervals)==0:
            return [newInterval]

        result = []
        i = 0
        while i < len(intervals) and newInterval[1] >= intervals[i][0]:
            interval = intervals[i]
            if self.intersecting(interval, newInterval):
                newInterval = [min(newInterval[0], interval[0]), max(newInterval[1], interval[1])]
            else:
                result.append(interval)
            i += 1
        result.append(newInterval)
        while i < len(intervals):
            result.append(intervals[i])
            i += 1

        return result