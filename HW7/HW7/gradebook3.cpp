#include <ostream>
#include <vector>
#include <iostream>
#include <memory>

using namespace std;
class GradeRecord {
public:
	GradeRecord(int id, double grade)
		: _studentId(id), _grade(grade)
	{}
	int getId() const { return _studentId; }
	void setGrade(double grade) { _grade = grade; }
	friend ostream& operator<<(ostream& out, const GradeRecord& record)
	{
		out << "RECORD: student #" << record._studentId << " grade = " <<
			record._grade << endl;
		return out;
	}
private:
	int _studentId;
	double _grade;
};

class Gradebook {
public:
	Gradebook()
		: _records()
	{}
	~Gradebook()
	{
		// cout << "Destroying record" << record._studentId << endl;
	}
	void addRecord(int studentId, double grade)
	{
		auto newRecord =  make_shared<GradeRecord>(studentId, grade);
		cout << "Record for student " << studentId << " added." << endl;
		_records.push_back(newRecord);
	}
	void updateRecord(int studentId, double grade)
	{
		shared_ptr<GradeRecord> record = nullptr; // Smart pointer of GradeRecord that refers to the nullptr FIRST, then whatever the pointer of the record you're looking for is.
		for (int i = 0; i < _records.size(); ++i)
		{
			if (_records.at(i)->getId() == studentId)
			{
				record = _records.at(i);
				break;
			}
		}
		if (record != nullptr)
		{
			record->setGrade(grade);
			cout << "Record for student " << studentId << " updated with a new grade of " << grade << "." << endl;
		}
	}
	friend ostream& operator<<(ostream& out, const Gradebook& gradebook)
	{
		out << "GRADEBOOK contains " << gradebook._records.size() << "students" << endl;
			for (int i = 0; i < gradebook._records.size(); i++)
				out << "\t" << *gradebook._records.at(i);
		return out;
	}
private:
	vector<shared_ptr<GradeRecord>> _records; // shared_ptr is the "smart pointer" to automate memory management.
};
int main()
{
	Gradebook* grades = new Gradebook();
		cout << *grades << endl;
	grades->addRecord(24, 3.1);
	grades->addRecord(129, 3.1);
	grades->addRecord(31, 3.1);
	grades->addRecord(44, 3.1);
	grades->addRecord(5, 3.1);
	cout << *grades << endl;
	grades->updateRecord(24, 4.0);
	grades->updateRecord(31, 4.0);
	cout << *grades << endl;
	// TODO cleanup the gradebook along with it's current graderecords
	// HINT: everything thas has been allocated on the heap needs to be deleted
	// HINT: deletion should be managed by resource owners, main owns the gradebook
		// and the gradebook owns the grade records
}