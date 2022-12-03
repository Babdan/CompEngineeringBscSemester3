// By Bogdan Itsam Dorantes-Nikolaev, COMP201 Lab, Instructor: Mustafa Ersen (October 14th, 2022)

// Chocolate class
public class Chocolate {

// Fields
	private String name;
	private String type;

// Chocolate constructor
	public Chocolate(String name, String type) {
	this.name = name;
	this.type = type;
	}

// toString method
@Override
	public String toString() {
		return "(N: " + name + ", T: " + type + ")";
	}
}