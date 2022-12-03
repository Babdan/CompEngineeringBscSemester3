// By Bogdan Itsam Dorantes-Nikolaev, COMP201 Lab, Instructor: Mustafa Ersen (October 14th, 2022)

//Pen class
public class Pen {

//Fields
	private String name;
	private String type;

//Pen constructor
	public Pen(String name, String type) {
		this.name = name;
		this.type = type;
	}

// toString method
@Override
	public String toString() {
		return "(N: " + name + ", T: " + type+")";
	}
}