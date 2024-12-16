# Python code​​​​​​‌‌​​​‌​​‌‌‌​​‌​​‌​‌‌‌​​​‌ below
# Use print("messages...") to debug your solution.

show_expected_result = True
show_hints = True

class InterceptingValidator():

    def __init__(self):
        self._validator = None
        self._input = "t" 

    def set_validator(self,validator):
        self._validator = validator

    def validate(self):
        return self._validator.validate(self._input)

class NumberValidator():
    """Checks if the input is a number or not """
    
    def validate(self, input):
        int_or_not = None

        try:
            user_input = int(input)
            print("Your input " + str(user_input) + " is an integer!")
            return True
            
        except ValueError:
            print("Your input " + input + " is not an integer!")
            return False
            

        return int_or_not

def check_input(ival):
    nval = NumberValidator()
    ival.set_validator(nval)    
    return ival.validate()


# This is how your code will be called.
# You can edit this code to try different testing cases.
ival = Answer.InterceptingValidator()
result = Answer.check_input(ival)