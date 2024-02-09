 class Solution:
    vis: Dict[int,bool] = {}
    finished: Set[int] = set()
    def dfs(self, u, adj: List[List[int]]) -> bool:
        if u in self.finished:
            return True
        if u in self.vis and self.vis[u]==True:
            return False
        self.vis[u] = True
        res = True
        for v in adj[u]:
            res = res and self.dfs(v, adj)
        self.vis[u] = False
        self.finished.add(u)
        return res

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj: List[List[int]] = [[] for _ in range(numCourses)]
        self.finished = set()
        self.vis = {}
        for l in prerequisites:
            adj[l[0]].append(l[1])
        res = True
        for i in range(numCourses):
            res = res and self.dfs(i, adj)
        return res