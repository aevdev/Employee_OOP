#include <iostream>
#include <fstream>

using namespace std;

#define EMPLOYEE_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age, const std::string& position
#define EMPLOYEE_GIVE_PARAMETERS last_name, first_name, age, position
class Employee
{
	std::string first_name;
	std::string last_name;
	unsigned int age;
	std::string position; //должность

public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	const std::string& get_position()
	{
		return position;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	void set_position(const std::string& position)
	{
		this->position = position;
	}

	virtual void print()const
	{
		cout << last_name << " " << first_name << " " << age << " years" << " " << position << endl;
	}
	virtual unsigned int get_Salary()const
	{
		return -1;//наверняка это все можно было сделать как-то иначе, но это первое, что пришло в голову.
	}

	// Constructors:
	Employee(EMPLOYEE_TAKE_PARAMETERS) : last_name(last_name), first_name(first_name), age(age), position(position)
	{

	}
	~Employee()
	{

	}
};

class ConstEmployee : public Employee
{
	unsigned int salary;

public:
	virtual unsigned int get_Salary() const override
	{
		return salary;
	}

	void set_Salary(unsigned int salary)
	{
		this->salary = salary;
	}

	void print()const
	{
		Employee::print();
		cout << "Salary: " << salary << endl;
	}
	// Constructors:
	ConstEmployee(EMPLOYEE_TAKE_PARAMETERS, unsigned int salary) : Employee(EMPLOYEE_GIVE_PARAMETERS), salary(salary)
	{

	}
	~ConstEmployee()
	{

	}
};

class PerHourEmployee : public Employee
{
	unsigned int salary;

public:
	virtual unsigned int get_Salary() const override
	{
		return salary;
	}

	void set_Salary(unsigned int salary)
	{
		this->salary = salary;
	}

	void print()const
	{
		Employee::print();
		cout << "Salary per hour: " << salary << endl;
	}
	// Constructors:
	PerHourEmployee(EMPLOYEE_TAKE_PARAMETERS, unsigned int salary) : Employee(EMPLOYEE_GIVE_PARAMETERS), salary(salary)
	{

	}
	~PerHourEmployee()
	{

	}
};
int main()
{
	int sum = 0;
	ConstEmployee Emp1("Emp1", "Emp1novich", 25, "Head Manager", 150);
	PerHourEmployee Emp2("Emp2", "Emp2novich", 24, "Head Manager", 15);
	PerHourEmployee Emp3("Emp3", "Emp3novich", 23, "Head Manager", 15);
	Employee* department[3] = { &Emp1, &Emp2, &Emp3 };
	cout << "\nFor each individual:";
	for (int i = 0; i < 3; ++i)
		cout << department[i]->get_first_name() << "Salary: " << department[i]->get_Salary() << endl;
	cout << "\nFor department:";
	for (int i = 0; i < 3; ++i)
		sum += department[i]->get_Salary();
	cout << "\nSalary of department: " << sum;



	return 0;
}