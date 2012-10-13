import java.util.*;

public class hw2{
  public static class addsub {
    public addsub(){}
    public int add(int a, int b){
      return a+b;
    }
    public int subtract(int a, int b){
      return a-b;
    }
  }
  public static void main(String[] args) {
    addsub stuff = new addsub();
    int x = stuff.add(82, 55);
    System.out.println(x);
  }
}