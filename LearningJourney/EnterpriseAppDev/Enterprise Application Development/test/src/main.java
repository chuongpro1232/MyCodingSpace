import java.util.ArrayList;
import java.util.List;

public class main {
    public static void main(String[] args) {
        List<String> listStringAction = List.of("Check", "Bet", "Call", "Fold");
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
    }
}
