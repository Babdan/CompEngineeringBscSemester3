// By Bogdan Itsam Dorantes-Nikolaev, COMP201 Lab, Instructor: Mustafa Ersen (October 14th, 2022)

// Importing the neccesary libraries
import java.util.ArrayList;

// Box class
public class Box<E> {

// Contents of the box
	private ArrayList<E> contents;

// Box instantiation
	public Box() {
		contents = new ArrayList<>();
	}

// Adding parameters to the item
	public void add(E item) {
		contents.add(item);
	}

// Removes period and addes the 'e'
	public E remove() {
		E item = contents.remove(contents.size() - 1);
		return item;
	}
	
// toString method
@Override
	public String toString() {
		String list = "";
		for (E e : contents) {
			list += e.toString() + "\n";
		}
		return list;
	}
}