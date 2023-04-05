#include <iostream>
#include <string>
#include <vector>
#include <map>

template <typename T>
void deleteElement(T &str, int index) {
    if (str.size() <= 0 || str.size() == index)
        return;

    for (int i = 0; i < str.size(); i++) {
        if (i >= index) {
            str[i] = str[i + 1];
        }
    }

    str.pop_back();
    return;
}

std::string strToСipher(std::string str) {
    std::map<char, std::string> cipher;

    cipher['a'] = "BBBBB";    cipher['g'] = "AABBA";     cipher['m'] = "ABBAA";    cipher['s'] = "BAABA";    cipher['y'] = "BBAAA";
    cipher['b'] = "AAAAB";    cipher['h'] = "AABBB";     cipher['n'] = "ABBAB";    cipher['t'] = "BAABB";    cipher['z'] = "BBAAB";
    cipher['c'] = "AAABA";    cipher['i'] = "ABAAA";     cipher['o'] = "ABBBA";    cipher['u'] = "BABAA";
    cipher['d'] = "AAABB";    cipher['j'] = "ABAAB";     cipher['p'] = "ABBBB";    cipher['v'] = "BABAB";
    cipher['e'] = "AABAA";    cipher['k'] = "ABABA";     cipher['q'] = "BAAAA";    cipher['w'] = "BABBA";
    cipher['f'] = "AABAB";    cipher['l'] = "ABABB";     cipher['r'] = "BAAAB";    cipher['x'] = "BABBB";

    cipher['A'] = "BBBBB";    cipher['G'] = "AABBA";     cipher['M'] = "ABBAA";    cipher['S'] = "BAABA";    cipher['Y'] = "BBAAA";
    cipher['B'] = "AAAAB";    cipher['H'] = "AABBB";     cipher['N'] = "ABBAB";    cipher['T'] = "BAABB";    cipher['Z'] = "BBAAB";
    cipher['C'] = "AAABA";    cipher['I'] = "ABAAA";     cipher['O'] = "ABBBA";    cipher['U'] = "BABAA";
    cipher['D'] = "AAABB";    cipher['J'] = "ABAAB";     cipher['P'] = "ABBBB";    cipher['V'] = "BABAB";
    cipher['E'] = "AABAA";    cipher['K'] = "ABABA";     cipher['Q'] = "BAAAA";    cipher['W'] = "BABBA";
    cipher['F'] = "AABAB";    cipher['L'] = "ABABB";     cipher['R'] = "BAAAB";    cipher['X'] = "BABBB";

    std::string code;
    for (int i = 0; i < str.size(); i++) {
        code += cipher[str[i]];
    }

    return code;
}
std::string cipherToStr(std::vector<std::string> VecCipher) {
    std::map<std::string, std::string> cipher;

    cipher["BBBBB"] = "a";    cipher["AABBA"] = "g";     cipher["ABBAA"] = "m";    cipher["BAABA"] = "s";    cipher["BBAAA"] = "y";
    cipher["AAAAB"] = "b";    cipher["AABBB"] = "h";     cipher["ABBAB"] = "n";    cipher["BAABB"] = "t";    cipher["BBAAB"] = "z";
    cipher["AAABA"] = "c";    cipher["ABAAA"] = "i";     cipher["ABBBA"] = "o";    cipher["BABAA"] = "u";
    cipher["AAABB"] = "d";    cipher["ABAAB"] = "j";     cipher["ABBBB"] = "p";    cipher["BABAB"] = "v";
    cipher["AABAA"] = "e";    cipher["ABABA"] = "k";     cipher["BAAAA"] = "q";    cipher["BABBA"] = "w";
    cipher["AABAB"] = "f";    cipher["ABABB"] = "l";     cipher["BAAAB"] = "r";    cipher["BABBB"] = "x";

    std::string str;
    for (int i = 0; i < VecCipher.size(); i++) {
        str += cipher[VecCipher[i]];
    }

    return str;
}

std::string strToUpperCase(std::string &text, std::string &code) {
    for (int i = 0; i < code.size(); i++) {
        if (i >= text.size())
            break;

        if (code[i] == 'B')
            text[i] -= 32;
    }

    return text;
}
std::string strToLowerCase(std::string &text, std::string &code) {
    for (int i = 0; i < code.size(); i++) {
        if (i >= text.size())
            break;

        if (text[i] >= 65 && text[i] <= 90)
            text[i] += 32;
    }

    return text;
}

std::vector<std::string> strToVecStr(std::string finishedText) {
    std::vector<std::string> vec;

    std::string TempVariable;
    for (int i = 1; i < finishedText.size() + 1; i++) {
        TempVariable += finishedText[i - 1];
        if (i % 5 == 0) {
            vec.push_back(TempVariable);
            TempVariable.clear();
        }
    }
    return vec;
}

void SomeFeature(std::vector<int> &indexs, std::string &text) {
    for (int i = 0; i < text.size(); i++) {
        int index = text.find(" ");

        if (index != std::string::npos) {
            indexs.push_back(index);
            deleteElement(text, index);
        }
    }
}
void SomeFeature2(std::vector<int> &indexs, std::string &text) {
    int counter = 0;
    for (int i = 0; i < indexs.size(); i++) {
        int num = indexs[i] + counter;

        text.insert(indexs[i] + counter, " ");
        counter++;
    }
}
void VecStrToCipher(std::vector<std::string>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < 5; j++) {
            if (vec[i][j] >= 97 && 122 >= vec[i][j])
            {
                vec[i][j] = 'A';
            }
            else if (vec[i][j] >= 65 && 90 >= vec[i][j])
            {
                vec[i][j] = 'B';
            }
        }
        if (vec[i] == "AAAAA")
            deleteElement(vec, i);
    }
}

std::string encryptStr(std::string text, std::string str) {
    std::vector<int> indexs;

    std::string code = strToСipher(str);

    // deleting " "
    SomeFeature(indexs, text);

    text = strToLowerCase(text, code);
    text = strToUpperCase(text, code);

    // returning " "
    SomeFeature2(indexs, text);

    return text;
}
std::string decryptStr(std::string text) {
    std::vector<std::string> vec;
    std::vector<int> indexs;

    // deleting " "
    SomeFeature(indexs, text);

    vec = strToVecStr(text);

    VecStrToCipher(vec);

    return cipherToStr(vec);
}

int main() {
    std::string text; // Welcome to the Hotel California Such a lovely place Such a lovely place
    std::string str; // Prometheus

    std::cout << "Enter the text where you want to hide the word/sentence: ";
    std::getline(std::cin, text);
    std::cout << "Enter word/sentence to encode it: ";
    std::getline(std::cin, str);

    system("cls");

    // result
    std::string encryptedText = encryptStr(text, str);
    std::cout << "Encrypted String: " << encryptedText << "\n";

    // code to str
    std::string decryptedText = decryptStr(encryptedText);
    std::cout << "Decrypted String: " << decryptedText << "\n";

    return EXIT_SUCCESS;
}

/*
Для кодування повідомлень Френсіс Бекон запропонував кожну літеру
тексту замінювати на групу з п"яти символів «А» або «B» (назвемо їх "ab-групами").

Таким чином, оригінальне повідомлення перетворюється на послідовність
ab-груп і може далі бути накладене на будь-який текст відповідної
довжини: А позначається нижнім регістром, В - верхнім.

Наприклад, початкове повідомлення - Prometheus.

1. Кодуємо його через ab-послідовності:

2. Підбираємо текст приблизно такої ж довжини, в якому сховаємо наше
повідомлення: Welcome to the Hotel California Such a lovely place Such a lovely place

3. Для зручності розбиваємо його на групи по 5 символів і відкидаємо
зайву частину (щоб при декодуванні не отримувалися зайві п"ятірки).
Співставимо ab-рядок і текст-сховище для порівняння:

abbab babab aabba bbaab abbbb babba bbbab abbbb abbaa ababb
Welco metot heHot elCal iforn iaSuc halov elypl aceSu chalo vely

4. Змінюємо регістр символів, кодуючи A та B:
abbab babab aabba bbaab abbbb babba bbbab abbbb abbaa ababb
wELcO MeToT heHOt ELcaL iFORN IaSUc HALoV eLYPL aCEsu cHaLO vely

5. Повертаємо початкові пробіли на місце:
wELcOMe To The HOtEL caLiFORNIa SUcH A LoVeLY PLaCE sucH a LOvely

Вхідні дані: масив символів, передається у функцію як аргумент. Може
містити пробіли та літери латинського алфавіту в будь-якому регістрі.
Результат роботи: дешифроване повідомлення.
*/
