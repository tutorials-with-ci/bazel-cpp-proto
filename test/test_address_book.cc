#include <sstream>
#include <string>
#include "gtest/gtest.h"
#include "proto/address_book.pb.h"

void PromptForAddress(tutorial::Person* person) {
  person->set_id(12138);
  person->set_name("SF-Zhou");
  person->set_email("sfzhou.scut@gmail.com");

  tutorial::Person::PhoneNumber* phone_number = person->add_phones();
  phone_number->set_number("13000000000");
  phone_number->set_type(tutorial::Person::MOBILE);
}

TEST(Proto, AddressBook) {
  std::stringstream ss;

  {
    tutorial::AddressBook address_book;
    PromptForAddress(address_book.add_people());
    ASSERT_TRUE(address_book.SerializeToOstream(&ss));
  }

  {
    tutorial::AddressBook address_book;
    address_book.ParseFromIstream(&ss);
    ASSERT_EQ(address_book.people_size(), 1);

    const tutorial::Person& person = address_book.people(0);
    ASSERT_EQ(person.email(), "sfzhou.scut@gmail.com");
  }

  google::protobuf::ShutdownProtobufLibrary();
}
