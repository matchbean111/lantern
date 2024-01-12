class BankAccount:
    def __init__(self,accountNumber, accountName, balance) -> None:
        self.accountNumber  = accountNumber
        self.accountName    = accountName
        self.balance        = balance
    

    def deposit(self, amount):
        self.balance = self.balance + amount

    def withdraw(self, amount):
        self.balance = self.balance - amount


    def __str__(self) -> str:
        return "({}, {})".format(self.accountName,
                                 self.balance)
    
    def __lt__(self,other):
        return self.balance < other.balance