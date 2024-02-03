class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        q = [(sr,sc)]

        while len(q) > 0:
            r,c = q[0]
            q.pop(0)
            if image[r][c]==color:
                continue
            if r+1 < len(image) and image[r+1][c]==image[r][c]:
                q.append((r+1,c))
            if r-1 >= 0 and image[r-1][c]==image[r][c]:
                q.append((r-1,c))
            if c+1 < len(image[0]) and image[r][c+1]==image[r][c]:
                q.append((r,c+1))
            if c-1 >= 0 and image[r][c-1]==image[r][c]:
                q.append((r,c-1))
            image[r][c] = color

        return image