#include <bits/stdc++.h>
#define endL "\n"
using namespace std;

class Task {
public:
    Task(const string& description) {
        this->description = description;
        completed = false;
    }
    void markCompleted() {
        completed = true;
    }

    bool isCompleted() const {
        return completed;
    }

    const string& getDescription() const {
        return description;
    }

private:
    string description;
    bool completed;
};

class TodoList {
public:
    void addTask(const string& description) {
        tasks.emplace_back(description);
        cout << "Task added successfully. "<< endL;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list yet." << endL;
            return;
        }
        cout << "Task List:" << endL;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].isCompleted()) cout << "[X] ";
            else cout << "[ ] ";
            cout << tasks[i].getDescription() << endL;
        }
    }

    void markTaskCompleted(const string& description) {
        for (Task& task : tasks) {
            if (task.getDescription() == description) {
                task.markCompleted();
                cout << "Task marked as completed. "<< endL;
                return;
            }
        }
        cout << "Task not found." << endL;
    }

    void removeTask(const string& description) {
        auto it = tasks.begin();
        while (it != tasks.end()) {
            if (it->getDescription() == description) {
                cout << "Task removed: " << description << endL;
                it = tasks.erase(it);
            }
            else ++it;
            if (it == tasks.end()) cout << "Task not found." << endL;
        }
    }

private:
    vector<Task> tasks;
};

int main() {
    TodoList list;
    int choice;
    string name;

    while (true) {
        cout << "\nTo-Do List" << endL;
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Quit" << endL;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:{
                cout << "Enter task name: ";
                cin.ignore();
                getline(cin, name);
                list.addTask(name);
                break;
            }
            case 2:
                list.viewTasks();
                break;
            case 3:
                cout << "Enter the task name to mark as completed: ";
                cin.ignore();
                getline(cin, name);
                list.markTaskCompleted(name);
                break;
            case 4:
                cout << "Enter the task name to remove: ";
                cin.ignore();
                getline(cin, name);
                list.removeTask(name);
                break;
            case 5:
                cout << "See you again :)" << endL;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endL;
                break;
        }
    }
}