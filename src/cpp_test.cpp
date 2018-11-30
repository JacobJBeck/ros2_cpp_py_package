// Jacob Beck

#include <chrono>
#include <rclcpp/rclcpp.hpp>

using namespace std::chrono_literals;

class CppTest : public rclcpp::Node {
 public:
  CppTest() : Node("cpptest"), count_(0) {
    timer_ = this->create_wall_timer(1s, std::bind(&CppTest::timer_callback_, this));
  }

 private:
  void timer_callback_() {
    RCLCPP_INFO(this->get_logger(), "Hello! %d", count_);
    count_++;
  }

  rclcpp::TimerBase::SharedPtr timer_;
  size_t count_;
};

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CppTest>());
  rclcpp::shutdown();
  return 0;
}
