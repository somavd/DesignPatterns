# Python code​​​​​​‌‌​​​‌​​‌‌‌​​‌​​‌​​‌‌​‌‌​ below
# Use print("messages...") to debug your solution.

show_expected_result = True
show_hints = False

class Command:
	def execute(self):
		pass

class Identify(Command):
	def execute(self):
		return "Identifying ..."

class Verify(Command):
	def execute(self):
		return "Verifying ..."

class Check(Command):
    def execute(self):
        return "Checking ..."
# Your code goes here

class Transaction:
	def __init__(self):
		self.commands = []

	def add(self, command):
		self.commands.append(command)

	def run(self):
		temp = None
		for o in self.commands:
			temp = o.execute()
			print(temp)
		return temp

def execute_actions(transaction):
    transaction.add(Check())
    return transaction.run()

transaction = Transaction()
result = execute_actions(transaction)