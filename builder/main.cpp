#include <iostream>
#include <memory>

using namespace std;
class BuilderInterface {
	public:
		BuilderInterface() = default;
		virtual BuilderInterface* add_roof() = 0;

		virtual BuilderInterface* add_yard() = 0;
};

class HomeBuilder : public BuilderInterface{
	public:
		HomeBuilder() = default;
		HomeBuilder* add_roof() override{
			std::cout << "adding roof ....\n";
			return this;
		}

		HomeBuilder* add_yard() override{
			std::cout << "adding backyard ....\n";
			return this;
		}
};

class Director {
	private:
		std::unique_ptr<BuilderInterface> builder_;
	public:
		Director(std::unique_ptr<BuilderInterface> builder) {
			builder_ = std::move(builder);
		}
		void build() {
			builder_->add_roof();
			builder_->add_yard();
		}
};
int main() {
	std::unique_ptr<BuilderInterface> builder = std::make_unique<HomeBuilder>();
	Director director(std::move(builder));
	director.build();

	return 0;
}
