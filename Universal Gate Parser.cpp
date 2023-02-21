#include <iostream>
#include <vector>

std::vector<std::string> _SplitRegularExpression(std::string RegularExpression, char splitBy);

std::string RealizeUsingNandGate(std::string RegularExpression);

std::string RealizeUsingNorGate(std::string RegularExpression);

std::string UniversalGateParser(std::string RegularExpression) {

	std::string NandExpression = RealizeUsingNandGate(RegularExpression),
		NorExpression = RealizeUsingNorGate(RegularExpression);

	std::cout << "NAND Exp : " << NandExpression;

	if (NandExpression.size() < NorExpression.size()) {

		return NandExpression;

	}

	return NorExpression;

}

int main() {

	UniversalGateParser("A + B + C + D");

}

std::string Nand(std::string A, std::string B, char Relation) {

	size_t x = A.size(), y = B.size();

	switch(Relation){

	case '+':
		return "(" + A + "#" + A + ")" + "#" + "(" + B + "#" + B + ")";
	case '#':
		return "(" + A + "#" + B + ")";
		
	}

	return "";

}

std::string RealizeUsingNandGate(std::string RegularExpression) {

	std::string NandExpression = "";

	std::vector<std::string>SplittedNandExpression;

	std::vector<std::string>SplittedRegularExpression = _SplitRegularExpression(RegularExpression, '+');

	size_t Size = SplittedRegularExpression.size();

	if (Size == 1) {

		return SplittedRegularExpression[0];

	}

	std::string LastExp = "";

	while (1) {

		if (Size & 1) {

			LastExp = SplittedRegularExpression[Size - 1];
			Size--;

		}

		for (size_t i = 0; i < Size; i += 2) {

			SplittedNandExpression.push_back(Nand(SplittedRegularExpression[i], SplittedRegularExpression[i + 1], '+'));

		}


		if (Size == 2) {

			if (LastExp != "") {

				NandExpression += Nand(SplittedNandExpression[0], LastExp, '+');
				LastExp = "";

			}
			else {

				NandExpression = SplittedNandExpression[0];

			}

			return NandExpression;

		}

		SplittedRegularExpression = SplittedNandExpression;

		SplittedNandExpression.clear();

		Size = Size / 2;

	}
	return NandExpression;

}

std::string RealizeUsingNorGate(std::string RegularExpression) {

	std::string NorExpression = "";



	return NorExpression;

}

std::vector<std::string> _SplitRegularExpression(std::string RegularExpression, char splitBy) {

	std::vector<std::string>SplittedRegularExpression;

	size_t Size = RegularExpression.size();

	std::string loopBuffer = "";

	for (size_t i = 0; i < Size; i++) {

		if (RegularExpression[i] == splitBy) {

			SplittedRegularExpression.push_back(loopBuffer);
			loopBuffer = "";

		}
		else {

			loopBuffer += RegularExpression[i];

		}

	}

	if (loopBuffer != "") {

		SplittedRegularExpression.push_back(loopBuffer);

	}

	return SplittedRegularExpression;

}