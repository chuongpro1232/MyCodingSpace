package rmitfreelancerweb.postgresql.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;
import rmitfreelancerweb.postgresql.model.User;

@Repository
public interface UserRepo extends JpaRepository<User, Long> {

}
