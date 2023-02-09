#include <iostream>
#include "SedManager.hpp"

#define SUCCESS 0
#define FAIL -1

SedManager::SedManager() {}
SedManager::~SedManager() {}

/*
	is_open 함수는 개체가 열린 파일과 정확히 연결돼있는 경우에는 true, 그렇지 않으면 false 반환

	clear 함수는 문자열에 뭐가 들어있을지 모르니 일단 비워주고 작업을 하기 위해 비워주는 함수.

	open 함수에서 2번째 옵션으로 std::ofstream::out을 넣어준 이유는 쓰기위한 파일을 열기 위해서임.

*/
int SedManager::check_valid_file(std::string infile, std::string outfile)
{
	infile_.open(infile, std::ifstream::in);
	if (!infile_.is_open())
	{
		std::cout << "Error: " << "Invalid infile." << std::endl;
		return (FAIL);
	}
	outfile_.open(outfile, std::ofstream::out);
	if (!outfile_.is_open())
	{
		std::cout << "Error: " << "Invalid outfile." << std::endl;
		return (FAIL);
	}
	buf_.clear();
	return (SUCCESS);
}

/*
	find 함수는 return 형식을 size_type으로 하기 때문에 pos 변수의 자료형을 size_type으로 선언한다.
	size_type : int 말고 이 형식을 사용하는 이유는 문자 개수가 얼마나 커지든 간에 그 값을 저장할 수 있도록 하기 위해서 (size_t)

	get_line 함수인자에 infile_를 넣어 infile내용을 buf_에 저장한다.
	pos : 검색

	find : 주어진 pattern이 buf_에 존재하는지 확인해본다. 찾으면 해당 문자열이 위치한 주소값을 반환, 못찾으면 npos 반환
	만약 맨 처음 찾았다면 erase와 insert 함수를 통해서 지우고, 대체한다.
	이 과정을 개행 기준으로 반복한다.
	그 다음 개행 출력


	npos : 상수 -> size_type으로 정의된 특수값이며 -1로 정의
	find() 함수에 의해서 found 되지 못하는 경우 npos값이 리턴된다.

	infile_.bad
	bad : bad 비트가 설정됐는지 확인한다.
	bad 비트는 만약 읽기 또는 쓰기 중에 오류가 발생하면 true를 뱉는다.
*/
int SedManager::replace_str(std::string pattern, std::string replacement)
{
	std::string::size_type pos = -1;

	while (std::getline(infile_, buf_))
	{
		pos = buf_.find(pattern, pos + 1);
		while (pos != std::string::npos)
		{
			buf_.erase(pos, pattern.length());
			buf_.insert(pos, replacement);
			pos = buf_.find(pattern, pos + 1);
		}
		outfile_ << buf_ << std::endl;
	}
	if (infile_.bad())
	{
		std::cout << "Error: " << "Failed while processing." << std::endl;
		return (FAIL);
	}
	return (SUCCESS);
}

void SedManager::close_file()
{
	if (infile_.is_open() == true)
		infile_.close();
	if (outfile_.is_open() == true)
		outfile_.close();
}
