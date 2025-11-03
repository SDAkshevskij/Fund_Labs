#ifndef SYSTEM_ERRORS_H
#define SYSTEM_ERRORS_H

#if defined(__apple__)

static const char *errors_arr[] = {
    "Операция не позволена",
    "Нет такого файла или каталога",
    "Нет такого процесса",
    "Прерван системный вызов",
    "Ошибка ввода/вывода",
    "Нет такого устройства или адреса",
    "Слишком длинный список параметров",
    "Ошибка формата исполняемого файла",
    "Неправильный дескриптор файла",
    "Отсутствуют дочерние процессы",
    "Ресурс временно недоступен ",
    "Недостаточно памяти",
    "Доступ запрещён",
    "Неправильный адрес",
    "Устройство или ресурс заняты",
    "Файл уже существует",
    "Не является каталогом",
    "Это каталог",
    "Неверный аргумент",
    "Слишком много открытых файлов у процесса",
    "Нет свободного места на устройстве"
};

#elif defined(__linux__)

static const char *errors_arr[] = {
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Device / Resource busy",
    "File exists",
    "Cross-device link",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "vInappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "27	EFBIG	File too large",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress"
    "Numerical argument out of domain"
};

#endif

#endif