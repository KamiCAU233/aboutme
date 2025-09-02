import java.util.Scanner;

public class StringToNumber {
    public static double StringToDouble(String s) {
        return Double.parseDouble(s);
    }
    public static int StringToInt(String s) {
        return Integer.parseInt(s);
    }
    //StudybarCommentBegin
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next(); // 读取输入的字符串
		if (s.indexOf('.') != -1) { // 判断字符串中是否含有小数点'.'
			double d = StringToDouble(s);// 编写此函数
			System.out.print(d);
		}
		else {
			int i = StringToInt(s);// 编写此函数
			System.out.print(i);
		}
	}

} // 注意此处只有主类结尾的括号！
//StudybarCommentEnd
