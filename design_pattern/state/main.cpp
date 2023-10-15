#include <chrono>
#include <future>
#include <iostream>
#include <memory>

using namespace std::chrono_literals;

class State {
  public:
    virtual bool do_switch() = 0;
    virtual bool check_to_switch() = 0;
    virtual ~State() = default;
};

class Controler {
  private:
    std::unique_ptr<State> state_;

  public:
    bool set_state(std::unique_ptr<State> state) {
        state_ = std::move(state);
        return true;
    }

    bool check() {
        if (!state_) {
            return false;
        }

        return state_->check_to_switch();
    }

    bool do_switch() { return state_->do_switch(); }
};

class NightState;

class DayState : public State {
  private:
    std::shared_ptr<Controler> controler;

  public:
    explicit DayState(std::shared_ptr<Controler> controler_) : State() {
        controler = controler_;
    }

    bool do_switch() override;

    bool check_to_switch() override {
        std::cout << "check to switch from day state\n";
        return true;
    }
};

class NightState : public State {
  private:
    std::shared_ptr<Controler> controler;

  public:
    explicit NightState(std::shared_ptr<Controler> controler_) {
        controler = controler_;
    }

    bool do_switch() override {
        controler->set_state(std::make_unique<DayState>(controler));
        return true;
    }

    bool check_to_switch() override {
        std::cout << "check to switch from night state\n";
        return true;
    }
};

bool DayState::do_switch() {
    controler->set_state(std::make_unique<NightState>(controler));
    return true;
}

int main() {
    std::shared_ptr<Controler> controler = std::make_shared<Controler>();
    std::unique_ptr<State> init_state = std::make_unique<DayState>(controler);

    controler->set_state(std::move(init_state));

    for (int i = 0; i < 3; i++) {
        if (controler->check()) {
            (void)controler->do_switch();
        }
    }

    return 0;
}
