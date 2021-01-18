#include "system_komunikacji.hpp"

Bank& System_komunikacji::zwroc_bank()
{
    return bank;
}

System_komunikacji::System_komunikacji(Bank& bank) : bank{bank}
{

}
