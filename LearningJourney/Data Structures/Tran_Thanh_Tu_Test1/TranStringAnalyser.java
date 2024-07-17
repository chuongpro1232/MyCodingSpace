package Tran_Thanh_Tu_Test1;

public class TranStringAnalyser {

    public static boolean isValid(String s) {
        LinkedListStac<Character> st = new LinkedListStack<character>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') {
                st.push(c);
                continue;
            }
            if (st.isEmpty()) {
                return false;
            }
            char c2 = st.peek();
            st.pop();
            if (c == ')' && c2 != '(') {
                return false;
            }
        }
        if (!st.isEmpty()) {
            return false;
        }
        return true;
    }// O(N)

    public static int totalPar(String s) {
        int total = 0;
        LinkedListStac<Character> st = new LinkedListStack<character>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') {
                total++;
            }
        }
        return total;
    }// O(N)

    public static int totalInsert(String s) {
        LinkedListStac<Character> st = new LinkedListStack<character>();
        int step = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') {
                if (c == '(') {
                    step++;      
                }
                if (c == ')') {
                    step--;
                }
            }
        }
        if (step < 0) {
            return step * -1;
        }
        return step;
    }// O(N)

    public static void main(String[] args) {
        // TranStringAnalyser s = new String ("(()())");
        System.out.println("(()()): " + isValid("(()())"));
        System.out.println("(: " + isValid("("));
        System.out.println("(()(()))): " + isValid("(()(())))"));
        System.out.println("))): " + isValid(")))"));

        System.out.println("(()()) Total Parenthesis: " + totalPar("(()()) Total Parenthesis: "));
    }
}