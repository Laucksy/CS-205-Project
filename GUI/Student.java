
/**
 * A student objext has instance variables about where their from, their GPA and oter things.
 * 
 * @author (Drew Carleton) 
 * @version (1.0)
 */
public class Student
{
    // instance variables - discribing the student
    private String lName="";
    private String fName="";
    private String Major="";
    private int Class=-1;
    private double GPA=-1;
    private String hTown="";

    /**
     * Constructor for objects of class Student
     */
    public Student(String last, String first, String major, int year, double gpa, String home)
    {
        // initialise instance variables
        fName=first;
        lName=last;
        Major=major;
        Class=year;
        GPA=gpa;
        hTown=home;
    }
    
    public Student()
    {
        
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public String getFirstName()
    {
        return fName;
    }
    
    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public String getLastName()
    {
        return lName;
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public String getMajor()
    {
        return Major;
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public int getTheClass()
    {
        return Class;
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public double getGPA()
    {
        return GPA;
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public String getHomeTown()
    {
        return hTown;
    }
    
    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public void setFirstName(String tempFname)
    {
        fName=tempFname;
    }
    
    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public void setLastName(String tempLname)
    {
        lName=tempLname;
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public void setMajor(String tempMajor)
    {
        Major=tempMajor;
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public void setClass(int tempClass)
    {
        Class=tempClass;
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public void setGPA(int tempGPA)
    {
        GPA=tempGPA;
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public void setHomeTown(String tempHome)
    {
        hTown=tempHome;
    }

}
