class Employee{//Parent class

	int salary;
    String name;
    int age;
    String Salary;
    int Bonus;

public Employee(String name, int salary, int age) {
        this.name = name;
        this.salary = salary;
        this.age = age;
    }


public String toString() {
    return "employee{" +
            "salary=" + salary +
            ", name='" + name + '\'' +
            ", age=" + age +
            ", Salary='" + Salary + '\'' +
            '}';
    }
public void showEmployeeInfo() {
        System.out.println(this.toString());
    }
}

