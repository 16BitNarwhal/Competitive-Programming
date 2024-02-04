class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])

        for r in range(m):
            for c in range(n):
                if mat[r][c]==0: continue
                mat[r][c] = min(mat[r-1][c] if r > 0 else 1e9, 
                                mat[r][c-1] if c > 0 else 1e9) + 1
        
        for r in range(m-1, -1, -1):
            for c in range(n-1, -1, -1):
                if mat[r][c]==0: continue
                mat[r][c] = min(mat[r][c],
                                mat[r+1][c]+1 if r < m-1 else 1e9,
                                mat[r][c+1]+1 if c < n-1 else 1e9)
        
        return mat