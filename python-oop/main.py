from Bank import BankAccount

b1 = BankAccount("56789", "Tom", 500)
b2 = BankAccount("12345", "Jerry", 190)

b1.withdraw(100)
b2.deposit(50)

print(b1.balance)
print(b2.balance)
print(b1 < b2)