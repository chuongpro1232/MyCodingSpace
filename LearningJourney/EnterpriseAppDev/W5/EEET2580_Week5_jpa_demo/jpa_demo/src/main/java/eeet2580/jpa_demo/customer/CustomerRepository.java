package eeet2580.jpa_demo.customer;

import org.springframework.data.jpa.repository.JpaRepository;

public interface CustomerRepository extends JpaRepository<CustomerInfo, Integer> {
    CustomerInfo findById(int customerId);

    CustomerInfoBalance findCustomerInfoById(int customerId);
}
