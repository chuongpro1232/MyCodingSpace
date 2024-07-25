package rmit.springboot_demo.user_profile;

import java.util.ArrayList;
import java.util.Optional;

import org.springframework.stereotype.Component;
@Component //we don't do this later on because we will use interface
public class UserProfileRespritory {
    private static ArrayList<UserProfileModel> userProfiles;
    public ArrayList<UserProfileModel> getUserProfiles(){
        return userProfiles;
    }
    public void initFakeUserProfiles(){
        userProfiles = new ArrayList <UserProfileModel>();
        userProfiles.add(new UserProfileModel("An", 1, 19, "female", 20_000, "1 Nguyen Van linh"));
        userProfiles.add(new UserProfileModel("John", 2, 25, "female", 20_000, "2 CMT8"));
        userProfiles.add(new UserProfileModel("Minnie", 3, 38, "female", 20_000, "3 Nguyen Chi Thanh"));
    }
    public Optional<UserProfileModel> findUserById(int id){
        Optional<UserProfileModel> foundUser = userProfiles.stream()
            .filter(user -> user.getId() == id)
            .findFirst();
        return foundUser;
    }
}

