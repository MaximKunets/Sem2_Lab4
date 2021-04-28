#include <iostream>
#include <chrono>
using namespace std;

struct Tree
{
    int value, depth;
	Tree* left,* right,* parent; 
};

void print_tree(Tree* curr);

Tree* balance(Tree* curr) { // обозначения, как на картинках в википедии в разделе балансировка
	Tree* a = curr;
	Tree* b = a->right;
	if (b != nullptr) {
		Tree* c = b->left;
		int d_l, d_r, d_c;

		if (c == nullptr) {
			d_c = 0;
		} else {
			d_c = c->depth;
		}
		if (a->left == nullptr) {
			d_l = 0;
		} else {
			d_l = a->left->depth;
		}
		if (b->right == nullptr) {
			d_r = 0;
		} else {
			d_r = b->right->depth;
		}

		if (b->depth - d_l == 2 && d_r >= d_c) { // малое левое вращение
			//cout << "l_1";
			a->right = c;
			b->left = a;
			b->parent = a->parent;
			if (b->parent != nullptr) {
				if (b->parent->right == a) {
					b->parent->right = b;
				} else {
					b->parent->left = b;
				}
			}
			a->parent = b;
			if (d_c != 0) {
				c->parent = a;
			}
			a->depth = max(d_l, d_c) + 1;
			b->depth = max(a->depth, d_r) + 1;
			return b;
		}

		if (c != nullptr) {
			Tree* m = c->left;
			Tree* n = c->right;
			int d_m, d_n;
			if (m == nullptr) {
				d_m = 0;
			} else {
				d_m = m->depth;
			}
			if (n == nullptr) {
				d_n = 0;
			} else {
				d_n = n->depth;
			}

			if (b->depth - d_l == 2 && d_r < c->depth) { // большое левое вращение
				//cout << "l_2";
				a->right = m;
				b->left = n;
				c->parent = a->parent;
				if (c->parent != nullptr) {
					if (c->parent->right == a) {
						c->parent->right = c;
					} else {
						c->parent->left = c;
					}
				}
				b->parent = c;
				a->parent = c;
				c->left = a;
				c->right = b;
				if (d_m != 0) {
					m->parent = a;
				}
				if (d_n != 0) {
					n->parent = b;
				}
				a->depth = max(d_m, d_l) + 1;
				b->depth = max(d_n, d_r) + 1;
				c->depth = max(a->depth, b->depth) + 1;
				return c;
			}
		}
	}

	b = a->left;
	if (b != nullptr) {
		int d_l, d_r, d_c;
		Tree* c = b->right;
		if (c == nullptr) {
			d_c = 0;
		} else {
			d_c = c->depth;
		}
		if (b->left == nullptr) {
			d_l = 0;
		} else {
			d_l = b->left->depth;
		}
		if (a->right == nullptr) {
			d_r = 0;
		} else {
			d_r = a->right->depth;
		}

		if (b->depth - d_r == 2 && d_c <= d_l) { // малое правое вращение
			//cout << "l_3 ";
			b->right = a;
			b->parent = a->parent;
			if (a->parent != nullptr) {
				if (a->parent->right == a) {
					a->parent->right = b;
				} else {
					a->parent->left = b;
				}
			}
			a->parent = b;
			a->left = c;
			if (d_c != 0) {
				c->parent = a;
			}
			a->depth = max(d_c, d_r) + 1;
			b->depth = max(a->depth, d_l) + 1;
			return b;
		}

		if (c != nullptr) {
			Tree* m = c->left;
			Tree* n = c->right;
			int d_m, d_n;
			if (m == nullptr) {
				d_m = 0;
			} else {
				d_m = m->depth;
			}
			if (n == nullptr) {
				d_n = 0;
			} else {
				d_n = n->depth;
			}

			if (b->depth - d_r == 2 && c->depth > d_l) {// большое правое вращение
				//cout << "l_4";
				b->right = m;
				a->left = n;
				if (d_m != 0) {
					m->parent = b;
				}
				if (d_n != 0) {
					n->parent = a;
				}
				c->parent = a->parent;
				if (a->parent != nullptr) {
					if (a->parent->right == a) {
						a->parent->right = c;
					} else {
						a->parent->left = c;
					}
				}
				b->parent = c;
				a->parent = c;
				c->left = b;
				c->right = a;
				a->depth = max(d_m, d_r) + 1;
				b->depth = max(d_n, d_l) + 1;
				c->depth = max(a->depth, b->depth) + 1;
				return c;
			}
		}
	}
}

Tree* change_depth_and_balance(Tree* curr) { //основная функция, балансирующая дерево
	int d_r, d_l;
	if (curr->right == nullptr) {
		d_r = 0;
	} else {
		d_r = curr->right->depth;
	}
	if (curr->left == nullptr) {
		d_l = 0;
	} else {
		d_l = curr->left->depth;
	}
	curr->depth = max(d_r, d_l) + 1;
	if (abs(d_l - d_r) > 1) {
		return balance(curr);
	}
	return curr;
}

Tree* insert(Tree* curr, int value) {
	if (curr == nullptr) {
		Tree* t_new = (Tree*)malloc(sizeof(Tree));
		t_new->value = value;
		t_new->right = nullptr;
		t_new->left = nullptr;
		t_new->depth = 1;

		return t_new;
	}
	if (value == curr->value) {
		return curr;
	} else {
		if (value > curr->value) {
			Tree* right = insert(curr->right, value);
			curr->right = right;
			right->parent = curr;
		} else {
			Tree* left = insert(curr->left, value);
			curr->left = left;
			left->parent = curr;
		}
		return change_depth_and_balance(curr);
	}
}

void time_insert(int n) {// я смотрю на время вставки каждых 1000 элементов
	char   c = '\n';
	FILE* fout;
	char m[] = "N - Time";
	fopen_s(&fout, "output_insert.txt", "w");
	fprintf(fout, "%s", m);
	fprintf(fout, "%c", c);
	Tree* curr = (Tree*)malloc(sizeof(Tree));
	curr->value = rand();
	curr->depth = 1;
	curr->left = nullptr;
	curr->right = nullptr;
	curr->parent = nullptr;
	float time = 0;
	for (int i = 1;i < n; ++i) {
		int value = rand();
		auto start = chrono::high_resolution_clock::now();
		curr = insert(curr, value);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<float> diff = end - start;
		time += diff.count();
		if (i % 1000 == 0) {
			char   s[] = "-";
			fprintf(fout, "%i", i);
			fprintf(fout, "%s", s);
			fprintf(fout, "%i", int(time * 1000000000));
			fprintf(fout, "%c", c);
			time = 0;
		}
		while (curr->parent) {
			curr = curr->parent;
		}
	}
}

bool serch(Tree* curr, int value) {
	if (curr == nullptr) {
		return false;
	}
	if (value == curr->value) {
		return true;
	}
	if (value > curr->value) {
		return serch(curr->right, value);
	} else {
		return serch(curr->left, value);
	}
}

void time_serch(int n) {
	char   c = '\n';
	FILE* fout;
	int value_serch;
	char m[] = "N - Time";
	fopen_s(&fout, "output_serch.txt", "w");
	fprintf(fout, "%s", m);
	fprintf(fout, "%c", c);
	Tree* curr = (Tree*)malloc(sizeof(Tree));
	curr->value = rand();
	curr->depth = 1;
	curr->left = nullptr;
	curr->right = nullptr;
	curr->parent = nullptr;
	float time = 0;
	for (int i = 1;i < n; ++i) {
		int value = rand() * 100000 + rand();
		curr = insert(curr, value);
		value_serch = rand() * 100000 + rand();
		auto start = chrono::high_resolution_clock::now();
		serch(curr, value_serch);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<float> diff = end - start;
		time += diff.count();
		if (i % 1000 == 0) {
			char   s[] = "-";
			fprintf(fout, "%i", i);
			fprintf(fout, "%s", s);
			fprintf(fout, "%i", int(time * 1000000000));
			fprintf(fout, "%c", c);
			time = 0;
		}
		while (curr->parent) {
			curr = curr->parent;
		}
	}
}

Tree* serch_1(Tree* curr, int value) { //лень переделывать serch, написал новый для delet_el
	if (curr == nullptr) {
		return nullptr;
	}
	if (value == curr->value) {
		return curr;
	}
	if (value > curr->value) {
		return serch_1(curr->right, value);
	} else {
		return serch_1(curr->left, value);
	}
}

Tree* delete_el(Tree* curr, int del_value) {
	Tree* need_del = serch_1(curr, del_value);
	if (need_del == nullptr) {
		return curr;
	}
	Tree* b = need_del->left;
	Tree* parent_del = need_del->parent;
	if (b == nullptr) {
		if (parent_del != nullptr) {
			if (parent_del->left == need_del) {
				parent_del->left = need_del->right;
			}
			if (parent_del->right == need_del) {
				parent_del->right = need_del->right;
			}
			if (need_del->right != nullptr) {
				need_del->right->parent = parent_del;
			}
			parent_del = change_depth_and_balance(parent_del);
			while (parent_del->parent) {
				parent_del = parent_del->parent;
				parent_del = change_depth_and_balance(parent_del);
			}
			return parent_del;
		} else {
			if (need_del->right != nullptr) {
				need_del->right->parent = nullptr;
			} else {
				need_del = nullptr;
			}
		}
	}
	int c = 0;
	while (b->right) {
		b = b->right;
		c += 1;
	}
	b->right = need_del->right;
	if (need_del->right != nullptr) {
		need_del->right->parent = b;
	}
	if (c > 0) {
		b->parent->right = nullptr;
		b->left = need_del->left;
		if (need_del->left != nullptr) {
			need_del->left->parent = b;
		}
	}
	b->parent = need_del->parent;
	if (need_del->parent != nullptr) {
		if (need_del->parent->left == need_del) {
			need_del->parent->left = b;
		}
		if (need_del->parent->right == need_del) {
			need_del->parent->right = b;
		}
	}

	b = change_depth_and_balance(b);
	while (b->parent) {
		b = b->parent;
		b = change_depth_and_balance(b);
	}
	return b;
}

void time_delete(int n) {
	char   c = '\n';
	FILE* fout;
	int value_del;
	char m[] = "N - Time";
	fopen_s(&fout, "output_delete.txt", "w");
	fprintf(fout, "%s", m);
	fprintf(fout, "%c", c);
	Tree* curr = (Tree*)malloc(sizeof(Tree));
	curr->value = rand();
	curr->depth = 1;
	curr->left = nullptr;
	curr->right = nullptr;
	curr->parent = nullptr;
	float time = 0;
	for (int i = 1;i < n; ++i) {
		int value = rand() * 100000 + rand();
		curr = insert(curr, value);
		value_del = rand() * 100000 + rand();
		auto start = chrono::high_resolution_clock::now();
		delete_el(curr, value_del);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<float> diff = end - start;
		time += diff.count();
		if (i % 1000 == 0) {
			char   s[] = "-";
			fprintf(fout, "%i", i);
			fprintf(fout, "%s", s);
			fprintf(fout, "%i", int(time * 1000000000));
			fprintf(fout, "%c", c);
			time = 0;
		}
		while (curr->parent) {
			curr = curr->parent;
		}
		value = rand() * 100000 + rand();
		curr = insert(curr, value);
	}
}

void print_tree(Tree* curr) {
	if (curr->left != nullptr) {
		print_tree(curr->left);
	}
	cout << curr->value << " ";
	if (curr->right != nullptr) {
		print_tree(curr->right);
	}
}

int main(){
	int n, value;
	/*Tree* head = (Tree*)malloc(sizeof(Tree));
	cout << "enter the number ofelements" << endl;
	cin >> n;
	head->value = rand();
	head->depth = 1;
	head->left = nullptr;
	head->right = nullptr;
	head->parent = nullptr;

	for (int i = 1; i < n; ++i) {
		value =  rand();
		head = insert(head, value);
		while (head->parent) {
			head = head->parent;
		}
		//print_tree(head);
		//cout << " " << head->value << endl;
	}

	while (head->parent) {
		head = head->parent;
	}
	print_tree(head);
	cout << endl << head->value;

	int del_value;
	cout << endl << "need del " <<  endl;
	cin >> del_value;
	head = delete_el(head, del_value);

	print_tree(head);
	cout << endl << head->value;*/
	cout << "Enter N" << endl;
	cin >> n;
	int c = 0;
	int choice;
	while (c == 0) {
		cout << "What do you want?" << endl << "1 - serch element" << endl << "2 - insert element" << endl << "3 - delete element" << endl <<
			"4 - exit" << endl;
		cin >> choice;
		if (choice == 4) {
			break;
		}
		if (choice == 2) {
			time_insert(n);
		}
		if (choice == 1) {
			time_serch(n);
		}
		if (choice == 3) {
			time_delete(n);
		}
	}
}