#include <iostream>
#include <vector>
using namespace std;

class Task {
public:
    string title;
    bool completed;

    Task(string t) {
        title = t;
        completed = false;
    }
};

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n===== TO-DO LIST APP =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {
            case 1: {
                string taskName;
                cout << "Enter task: ";
                getline(cin, taskName);

                tasks.push_back(Task(taskName));
                cout << "Task added successfully!\n";
                break;
            }

            case 2: {
                if (tasks.empty()) {
                    cout << "No tasks available.\n";
                } else {
                    cout << "\nTasks:\n";
                    for (int i = 0; i < tasks.size(); i++) {
                        cout << i + 1 << ". "
                             << tasks[i].title
                             << " [" << (tasks[i].completed ? "Done" : "Pending") << "]\n";
                    }
                }
                break;
            }

            case 3: {
                int index;
                cout << "Enter task number to complete: ";
                cin >> index;

                if (index > 0 && index <= tasks.size()) {
                    tasks[index - 1].completed = true;
                    cout << "Task marked as completed.\n";
                } else {
                    cout << "Invalid task number.\n";
                }
                break;
            }

            case 4: {
                int index;
                cout << "Enter task number to delete: ";
                cin >> index;

                if (index > 0 && index <= tasks.size()) {
                    tasks.erase(tasks.begin() + index - 1);
                    cout << "Task deleted successfully.\n";
                } else {
                    cout << "Invalid task number.\n";
                }
                break;
            }

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
