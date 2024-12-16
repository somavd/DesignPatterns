# Python code​​​​​​‌‌​​​‌​​‌​​‌​‌‌‌​​‌​‌​‌​​ below
# Use print("messages...") to debug your solution.

show_expected_result = False
show_hints = False

class Director():
    """Director"""
    def __init__(self, builder):
        self._builder = builder 
        
    def construct_account(self):
        self._builder.create_new_account()
        self._builder.add_type();
        self._builder.add_id();
        self._builder.add_clearance();
        #Your code goes here
        
    def get_account(self):
        return self._builder.account

class Builder():
    """Abstract Builder"""
    def __init__(self):
        self.account = None 
        
    def create_new_account(self):
        self.account = Account()

class StudentAccountBuilder(Builder):
    """Concrete Builder --> builds parts and assembles them """
    
    def add_type(self):
        self.account.type = "student"

    def add_id(self):
        self.account.id = "123"

    def add_clearance(self):
        self.account.clearance = "middle"

class Account():
    """Product"""
    def __init__(self, type, id, clearance):
        self.type = type
        self.id = id
        self.clearance = clearance

    def __init__(self):
        self.type = None
        self.id = None
        self.clearance = None
        
    def __eq__(self, other):
        return (self.type, self.id) == (other.type, other.id)

    def __str__(self):
        return '{} | {} | {}'.format(self.type, self.id, self.clearance)

def create_account(director):
    director.construct_account()
    accountt = director.get_account()
    return accountt

builder = StudentAccountBuilder()
director = Director(builder)
result = create_account(director)
print(result)