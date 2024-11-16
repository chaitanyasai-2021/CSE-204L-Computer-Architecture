f= open("Employee.txt","w+")
f.close()


with open("Employee.txt", "w") as file:
    file.write("{:<20}{:<10}{:<20}{:<15}\n".format("EmpName", "EmpId", "EmpDesig", "EmpSalary"))
    
    num_employees = int(input("Enter the number of employees: "))
    for _ in range(num_employees):
        emp_name = input("Enter EmpName: ")or "NA"
        emp_id = input("Enter EmpId: ")or "NA"
        emp_desig = input("Enter EmpDesig: ")or "NA"
        emp_salary = input("Enter EmpSalary: ")or "NA"
        file.write("{:<20}{:<10}{:<20}{:<15}\n".format(emp_name, emp_id, emp_desig, emp_salary))