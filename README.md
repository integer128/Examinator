# Examinator

Лабораторная работа 1
Дисциплина «Мультимедиа технологии в образовании»

Постанова задачи:
Необходимо разработать приложение (обучающую систему), которое предоставляет обучаемому информацию по данной теме, 
позволяет пройти тестирование.
Система должна содержать любые два модуля из трех предложенных:
1. модуль обеспечения работы с учебным материалом («Изучение теории»);
2. модуль работы с учебно-тренировочными задачами («Проверь себя»);
3. модуль генерации учебно-тренировочных задач («Генерация заданий»).

Общие требования к системе:
1. Программа должна поддерживать два типа пользователей:
а) Студент. Имеет возможность ознакомиться с курсом и пройти тестирование.
б) Преподаватель. Имеет возможность редактирования теоретической информации и вопросов теста, просмотра результатов тестирования студентов.

2. При создании нового пользователя информация о нем заносится в базу данных. 
Должны храниться ID, имя, отчество, фамилия, пароль. В базе также должны храниться последняя дата тестирования студента, 
набранные баллы, единицы теоретического материала, вопросы и ответы теста.

3. Интерфейс программы должен включать
а) Вход / Выход.
б) Меню (переход в модули). Обратные переходы с этих страниц на главную.
4. Оформление интерфейса должно быть продуманным, удобным.
5. Продумать защиту от некорректных действий пользователя.

Требования к модулю «Изучение теории».
1. Модуль должен содержать 3 раздела (параграфа) темы. Тема – любая.
2. Каждый раздел должен содержать теоретический материал (1 стр.)
3. Теоретический материал должен содержать минимум 1 рисунок, 1 видеоролик, 1 анимацию, 
звуковое сопровождение (весь материал, а не каждый параграф).
4. Структура экрана должна содержать несколько информационных зон: фон; текст; 
кнопки и объекты для интерактивного управления просмотром.
5. Оформление должно быть удобным для пользователя.

Повышенный уровень. Дополнительно к перечисленным: (+5 баллов)
6. Возможность редактирования преподавателем страниц с теорией.
7. Возможность скрытия преподавателем темы от студента.

Требования к модулю «Проверь себя».
1. Обучаемому предъявляются по 3 вопроса двух типов – ввод ответа (текстовый или числовой), 
выбор одного правильного из множества (с использованием переключателя).
2. После ответа на вопрос обучаемый должен видеть, верно или неверно он ответил.
3. При неверном ответе у обучаемого должна быть возможность перейти к соответствующему разделу 
теории для повторения или к разделу справочных материалов.
4. Предоставить обучаемому возможность повторно ответить на вопросы.

Повышенный уровень. Дополнительно к перечисленным: (+5 баллов)
5. По 2 вопроса других типов - выбор нескольких правильных из множества (с использованием флажков) и на соответствие.
6. Преподавателю предоставить возможность добавления, редактирования вопросов

Требования к модулю «Генерация заданий».
Выбранные разделы для генерации обсудить с преподавателем. 
Например, если выбрана тема по математике, минимальная сложность заданий – квадратные уравнения.
При генерации используется ограниченное количество данных (до 20 записей). Генерация происходит с помощью случайной выборки 
из заранее определенного набора с исключением повторения заданий. Задания поочередно предъявляются пользователю.

Повышенный уровень (+5 баллов)
Генерация автоматизирована или частично автоматизирована. Продумано заполнение базы заданий достаточным количеством данных (порядка 1000)
и просмотр или составление заданий в режиме реального времени.
