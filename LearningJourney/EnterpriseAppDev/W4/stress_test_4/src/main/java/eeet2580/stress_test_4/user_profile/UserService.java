package eeet2580.stress_test_4.user_profile;

import org.springframework.stereotype.Component;
import org.springframework.stereotype.Service;

@Component
public class UserService {
    public String showProfileAsStr(int userId){
        return """
                ID: %d, </br>
                Name: %s, </br>
                balance: %.2f </br>
                """.formatted(
                    1,
                    "Hoang",
                    20.90
                );
    }
    UserProfile showProfileAsObj(int userId){
        UserProfile user = new UserProfile ( "Hoang",1, 20.90);
        return user;
    }
}
