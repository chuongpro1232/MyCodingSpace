import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.stream.Collectors;
import java.util.stream.Stream;
import java.util.ArrayList;
import java.util.List;

public class App {
    public static void main(String[] args) {
        System.out.println("------------------------------------------------");
        System.out.println("---------------------Part 1---------------------");
        List<String> listStringAction = List.of("CHECK", "BET", "CALL", "FOLD");
        List<String> sequenceString = new ArrayList<>();
        String stringAction = "";

        for (int i = 0; i < 2; i++) {
            if (i == 1) {
                for (int l = 2; l < 4; l++) {
                    for (int m = 2; m < 4; m++) {
                        stringAction =  listStringAction.get(i) + "-" + listStringAction.get(l) + "-" + listStringAction.get(m);
                        sequenceString.add(stringAction);
                   }
                }
            }
            else {
                for (int j = 0; j < 2; j++) {
                    if (j == 1) {
                        for (int l = 2; l < 4; l++) {
                            for (int m = 2; m < 4; m++) {
                                stringAction =  listStringAction.get(i) + "-" + listStringAction.get(j) + "-" + listStringAction.get(l) + "-" + listStringAction.get(m);
                                sequenceString.add(stringAction);
                            }
                        }
                    }
                    else {
                        for (int k = 0; k < 2; k++) {
                            if (k == 1) {
                                for (int l = 2; l < 4; l++) {
                                    for (int m = 2; m < 4; m++) {
                                        stringAction =  listStringAction.get(i) + "-" + listStringAction.get(j) + "-" + listStringAction.get(k) + "-" + listStringAction.get(l) + "-" + listStringAction.get(m);
                                        sequenceString.add(stringAction);
                                    }
                                }
                            }
                            else {
                                sequenceString.add(listStringAction.get(i) + "-" + listStringAction.get(j) + "-" + listStringAction.get(k));
                            }
                        }
                    }
                }
            }
        }
        sequenceString.forEach(System.out::println);

        System.out.println("------------------------------------------------");
        System.out.println("---------------------Part 2---------------------");

        for(int i = 0; i < sequenceString.size(); i++){
            int Pot = CheckBetCall(sequenceString, i);
            System.out.println(sequenceString.get(i) + " = " + Pot);
        }

        System.out.println("------------------------------------------------");
        System.out.println("---------------------Part 3---------------------");
        String stringAction3 = "";
        List<String> sequenceString3 = new ArrayList<>();
        int Pot = 0;

        for (int i = 0; i < 2; i++) {
            if (i == 1) {
                stringAction3 = listStringAction.get(i);
                sequenceString3.add(stringAction3);
                for (int l = 2; l < 4; l++) {
                    String tmp = stringAction3 + "-" + listStringAction.get(l);
                    sequenceString3.add(tmp);
                    for (int m = 2; m < 4; m++) {
                        String tmp1 = tmp + "-" + listStringAction.get(m);
                        sequenceString3.add(tmp1);
                    }
                }
            }
            else {
                stringAction3 =  listStringAction.get(i);
                String tmp = stringAction3;
                sequenceString3.add(stringAction3);
                for (int j = 0; j < 2; j++) {
                    if (j == 1) {
                        tmp += "-" + listStringAction.get(j);
                        sequenceString3.add(tmp);
                        for (int l = 2; l < 4; l++) {
                            String tmp1 = tmp + "-" + listStringAction.get(l);
                            sequenceString3.add(tmp1);
                            for (int m = 2; m < 4; m++) {
                                String tmp2 = tmp1 + "-" + listStringAction.get(m);
                                sequenceString3.add(tmp2);
                            }
                        }
                    }
                    else {
                        stringAction3 +=  "-" + listStringAction.get(j);
                        String tmp3 = stringAction3;
                        sequenceString3.add(stringAction3);
                        for (int k = 0; k < 2; k++) {
                            if (k == 1) {
                                tmp3 += "-" + listStringAction.get(k);
                                sequenceString3.add(tmp);
                                for (int l = 2; l < 4; l++) {
                                    String tmp4 = tmp3 + "-" + listStringAction.get(l);
                                    sequenceString3.add(tmp4);
                                    for (int m = 2; m < 4; m++) {
                                        String tmp5 = tmp4 + "-" + listStringAction.get(m);
                                        sequenceString3.add(tmp5);
                                    }
                                }
                            }
                            else {
                                stringAction3 += "-" + listStringAction.get(k);
                                sequenceString3.add(stringAction3);
                            }
                        }
                    }
                }
            }
        }

        for(int i = 0; i < sequenceString3.size(); i++){
            int Pot1 = CheckBetCall(sequenceString3, i);
            System.out.println(sequenceString3.get(i) + " = " + Pot1);
        }
    }
    public static int CheckBetCall(List<String> sequenceString, int i){
        Pattern P_bet = Pattern.compile("BET");
        Pattern P_call = Pattern.compile("CALL");
        int Pot = 60;
        int count = 0;
        Matcher m1 = P_bet.matcher(sequenceString.get(i));
        Matcher m2 = P_call.matcher(sequenceString.get(i));
        while (m1.find() || m2.find())
        {
            count +=1;
        }
        Pot += 10*count;
        return Pot;
    }

    public static int CheckBetCall(String sequenceString){
        Pattern P_bet = Pattern.compile("BET");
        Pattern P_call = Pattern.compile("CALL");
        int Pot = 60;
        int count = 0;
        Matcher m1 = P_bet.matcher(sequenceString);
        Matcher m2 = P_call.matcher(sequenceString);
        while (m1.find() || m2.find())
        {
            count +=1;
        }
        Pot += 10*count;
        return Pot;
    }
}





