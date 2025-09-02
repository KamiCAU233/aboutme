import java.util.*;

class Fraction implements Comparable<Fraction> {
    public int numer;
    public int denom;
    public Fraction(int n, int d) {
        int gcd = getGCD(n, d);
        numer = n / gcd;
        denom = d / gcd;
    }
    public static int getGCD(int a, int b) {
        if (b == 0) {
            return a;
        }
        return getGCD(b, a % b);
    }
    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }
        Fraction other = (Fraction) obj;
        return numer == other.numer && denom == other.denom;
    }

    @Override
    public int hashCode() {
        return 31 * denom + numer;
    }
    @Override
    public int compareTo(Fraction f) {
        return (numer * f.denom - denom * f.numer);
    }
    public static Fraction parseFraction(String str) {
        String[] parts = str.split("/");
        int num = Integer.parseInt(parts[0]);
        int den = Integer.parseInt(parts[1]);
        return new Fraction(num, den);
    }
    public void print() {
        System.out.print(numer);
        if (denom != 1) {
            System.out.print("/" + denom);
        }
    }
}

public class FractionSet {
    public static void printSet(Set<Fraction> set) {
        if (set.isEmpty()) {
            System.out.print("empty");
        } else {
            for (Fraction f : set) {
                f.print();
                System.out.print(" ");
            }
        }
        System.out.print("\n");
    }
    public static void main(String[] args) {
        Set<Fraction> set1 = new TreeSet<>();
        Set<Fraction> set2 = new TreeSet<>();
        Scanner sc = new Scanner(System.in);
        String[] s1 = sc.nextLine().split(" ");
        String[] s2 = sc.nextLine().split(" ");
        for (String x : s1) {
            set1.add(Fraction.parseFraction(x));
        }
        for (String x : s2) {
            set2.add(Fraction.parseFraction(x));
        }
        // Find intersection
        Set<Fraction> intersection = new TreeSet<>(set2);
        intersection.retainAll(set1);
        // Find union
        Set<Fraction> union = new TreeSet<>(set1);
        union.addAll(set2);
        // Find complement
        Set<Fraction> complement = new TreeSet<>(set1);
        complement.removeAll(set2);
        // Print out the result
        printSet(intersection);
        printSet(union);
        printSet(complement);
     }
}
