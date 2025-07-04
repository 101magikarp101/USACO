import java.util.*;
import java.io.*;

public class Prob2 {
  public static void main(String[] args) throws FileNotFoundException {
    long[] vals = new long[3];
    HashMap<String, Integer> map = new HashMap<String, Integer>();
    map.put("red", 0);
    map.put("green", 1);
    map.put("blue", 2);
    long ans = 0;
    Scanner sc = new Scanner(new File("2.txt"));
    while (sc.hasNext()) {
      String[] line = sc.nextLine().trim().split(":");
      String[] a = line[1].trim().split(";");
      vals = new long[3];
      for (int i = 0; i < a.length; i++) {
        String[] b = a[i].trim().split(",");
        for (int j = 0; j < b.length; j++) {
          String[] c = b[j].trim().split(" ");
          long x = Integer.parseInt(c[0].trim());
          int col = map.get(c[1].trim());
          vals[col] = Math.max(vals[col], x);
        }
      }
      ans += vals[0] * vals[1] * vals[2];
    }
    System.out.println(ans);
  }
}