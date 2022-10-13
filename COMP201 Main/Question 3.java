// By Bogdan Itsam Dorantes-Nikolaev, COMP201, Instructor: Prof. Adem Karahoca (October 13th, 2022)

@Override
public int getClientAreaHeight() {
	return super.getClientAreaHeight() - 2 * borderSize;
}