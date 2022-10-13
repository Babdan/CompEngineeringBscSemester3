// By Bogdan Itsam Dorantes-Nikolaev, COMP201, Instructor: Prof. Adem Karahoca (October 13th, 2022)

public class CalculatorWithMemory extends Calculator {

	private double memory = 0;
	
	public void save() {
		memory = accumulator;
	}

	public void recall() {
		accumulator = memory;
	}

	public void clearMemory() {
		memory = 0;
	}

	public double getMemory() {
		return memory;
	}
	
}