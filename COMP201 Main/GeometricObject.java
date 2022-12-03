// By Bogdan Itsam Dorantes-Nikolaev, COMP201, Instructor: Prof. Adem Karahoca (October 22nd, 2022)

// Project: Enabling GeometricObject comparable
public class GeometricObject {
    // Main method
    public static void main(String[] args) {
        // Create two comparable circles
        Circle1 circle1 = new Circle1(5);
        Circle1 circle2 = new Circle1(4);

        // Display the max circle
        Circle1 circle = (Circle1) GeometricObject1.max(circle1, circle2);
        System.out.println("The max circle's radius is " + circle.getRadius());
        System.out.println(circle);
    }
}

// Implement the Comparable interface
abstract class GeometricObject1 implements Comparable<GeometricObject1> {
    protected String color;
    protected double weight;

    // Construct a default geometric object
    protected GeometricObject1() {
        color = "white";
        weight = 1.0;
    }

    // Construct a geometric object
    protected GeometricObject1(String color, double weight) {
        this.color = color;
        this.weight = weight;
    }

    // Getter and setter methods for color and weight
    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    // Abstract method
    public abstract double getArea();

    // Abstract method
    public abstract double getPerimeter();

    // Implement the compareTo method defined in Comparable
    public int compareTo(GeometricObject1 o) {
        if (getArea() < o.getArea())
            return -1;
        else if (getArea() == o.getArea())
            return 0;
        else
            return 1;
    }

    // Implement the max method in the Comparable interface
    public static GeometricObject1 max(GeometricObject1 o1, GeometricObject1 o2) {
        if (o1.compareTo(o2) > 0)
            return o1;
        else
            return o2;
    }
}

// Class extends GeometricObject
class Circle1 extends GeometricObject1 {
    protected double radius;

    // Construct a default circle
    public Circle1() {
        this(1.0, "white", 1.0);
    }

    // Construct a circle with specified radius
    public Circle1(double radius) {
        super("white", 1.0);
        this.radius = radius;
    }

    // Construct a circle with specified radius, weight, and color
    public Circle1(double radius, String color, double weight) {
        super(color, weight);
        this.radius = radius;
    }

    // Getter and setter methods for radius
    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    // Implement the getArea method defined in GeometricObject
    public double getArea() {
        return radius * radius * Math.PI;
    }

    //
    public double getPerimeter() {
        return 2 * radius * Math.PI;
    }

    // Override the toString method defined in the Object class
    public boolean equals(Circle1 circle) {
        return this.radius == circle.getRadius();
    }

    @Override
    public String toString() {
        return "[Circle] radius = " + radius;
    }

    @Override
    public int compareTo(GeometricObject1 o) {
        if (getRadius() > ((Circle1) o).getRadius())
            return 1;
        else if (getRadius() < ((Circle1) o).getRadius())
            return -1;
        else
            return 0;
    }
}