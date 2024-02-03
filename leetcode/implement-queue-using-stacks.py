# amortized
class MyQueue:

    def __init__(self):
        self.buffer = [] # holds until retrieve is empty
        self.retrieve = [] # acts as the "front" of the queue

    def push(self, x: int) -> None:
        self.buffer.append(x)

    def pop(self) -> int:
        if len(self.retrieve)==0:
            self.load_buffer()
        return self.retrieve.pop()

    def peek(self) -> int:
        if len(self.retrieve)==0:
            self.load_buffer()
        return self.retrieve[-1]

    def empty(self) -> bool:
        return len(self.retrieve) == 0 and len(self.buffer) == 0

    def load_buffer(self):
        while len(self.buffer)>0:
            self.retrieve.append(self.buffer.pop())