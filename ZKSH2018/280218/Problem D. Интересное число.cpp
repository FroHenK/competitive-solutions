#include <bits/stdc++.h>


using namespace std;
#define __int64 __int64_t

string n;
int ark[20];
int oka[20];

__int64 n1;
__int64 nsq;
string norig;
const int INF = 1000000;


void solve() {

    long hl = n.size() / 2;
    long l = n.size();
    if (hl > 6)
        exit(1);
    if (!l)
        exit(1);
    norig = n;
    nsq = static_cast<__int64_t>(sqrtl(n1) + 1);
    set<__int64> st;
    if (n.find('0') != -1)
        st.insert(0);
    memset(ark, 0, sizeof ark);

    sort(n.begin(), n.end());


    for (int i = 0; i < l; ++i) {
        ark[i] = n[i] - '0';
        if (n[i] < '0' || n[i] > '9')
            exit(1);
    }
    hl += 3;
    __int64 t1 = 0;
    if (hl >= 0) {
        for (int v0 = 0; v0 < l; ++v0) {
            if (!ark[v0])continue;
            t1 += ark[v0] * 1ll;
            if (t1 > nsq) {
                t1 -= ark[v0] * 1ll;
                break;
            }
            __int64 value = t1;
            value *= value;
            memset(oka, 0, sizeof oka);
            for (int i = 0; i < l; ++i)oka[ark[i]] += 1;
            __int64 t2 = value;
            if (value > 0) {
                oka[value % 10] -= 1;
                if (oka[value % 10] < 0) {
                    t1 -= ark[v0] * 1ll;
                    continue;
                };
                value /= 10;
            }
            if (value > 0) {
                oka[value % 10] -= 1;
                if (oka[value % 10] < 0) {
                    t1 -= ark[v0] * 1ll;
                    continue;
                };
                value /= 10;
            }
            if (value > 0) {
                oka[value % 10] -= 1;
                if (oka[value % 10] < 0) {
                    t1 -= ark[v0] * 1ll;
                    continue;
                };
                value /= 10;
            }
            if (value > 0) {
                oka[value % 10] -= 1;
                if (oka[value % 10] < 0) {
                    t1 -= ark[v0] * 1ll;
                    continue;
                };
                value /= 10;
            }
            if (value > 0) {
                oka[value % 10] -= 1;
                if (oka[value % 10] < 0) {
                    t1 -= ark[v0] * 1ll;
                    continue;
                };
                value /= 10;
            }
            if (value > 0) {
                oka[value % 10] -= 1;
                if (oka[value % 10] < 0) {
                    t1 -= ark[v0] * 1ll;
                    continue;
                };
                value /= 10;
            }
            if (value > 0) {
                oka[value % 10] -= 1;
                if (oka[value % 10] < 0) {
                    t1 -= ark[v0] * 1ll;
                    continue;
                };
                value /= 10;
            }
            if (value > 0) {
                oka[value % 10] -= 1;
                if (oka[value % 10] < 0) {
                    t1 -= ark[v0] * 1ll;
                    continue;
                };
                value /= 10;
            }
            if (value > 0) {
                oka[value % 10] -= 1;
                if (oka[value % 10] < 0) {
                    t1 -= ark[v0] * 1ll;
                    continue;
                };
                value /= 10;
            }
            if (value > 0) {
                oka[value % 10] -= 1;
                if (oka[value % 10] < 0) {
                    t1 -= ark[v0] * 1ll;
                    continue;
                };
                value /= 10;
            }
            if (value > 0) {
                oka[value % 10] -= 1;
                if (oka[value % 10] < 0) {
                    t1 -= ark[v0] * 1ll;
                    continue;
                };
                value /= 10;
            }
            if (value > 0) {
                oka[value % 10] -= 1;
                if (oka[value % 10] < 0) {
                    t1 -= ark[v0] * 1ll;
                    continue;
                };
                value /= 10;
            }
            if (value > 0) {
                oka[value % 10] -= 1;
                if (oka[value % 10] < 0) {
                    t1 -= ark[v0] * 1ll;
                    continue;
                };
                value /= 10;
            }
            st.insert(t1);
            t1 -= ark[v0] * 1ll;
        }
    }
    if (hl >= 2) {
        for (int v0 = 0; v0 < l; ++v0) {
            if (!ark[v0])continue;
            t1 += ark[v0] * 10ll;
            if (t1 > nsq) {
                t1 -= ark[v0] * 10ll;
                break;
            }
            for (int v1 = 0; v1 < l; ++v1) {
                t1 += ark[v1] * 1ll;
                if (t1 > nsq) {
                    t1 -= ark[v1] * 1ll;
                    break;
                }
                if (v1 == v0) {
                    t1 -= ark[v1] * 1ll;
                    continue;
                }
                __int64 value = t1;
                value *= value;
                memset(oka, 0, sizeof oka);
                for (int i = 0; i < l; ++i)oka[ark[i]] += 1;
                __int64 t2 = value;
                if (value > 0) {
                    oka[value % 10] -= 1;
                    if (oka[value % 10] < 0) {
                        t1 -= ark[v1] * 1ll;
                        continue;
                    };
                    value /= 10;
                }
                if (value > 0) {
                    oka[value % 10] -= 1;
                    if (oka[value % 10] < 0) {
                        t1 -= ark[v1] * 1ll;
                        continue;
                    };
                    value /= 10;
                }
                if (value > 0) {
                    oka[value % 10] -= 1;
                    if (oka[value % 10] < 0) {
                        t1 -= ark[v1] * 1ll;
                        continue;
                    };
                    value /= 10;
                }
                if (value > 0) {
                    oka[value % 10] -= 1;
                    if (oka[value % 10] < 0) {
                        t1 -= ark[v1] * 1ll;
                        continue;
                    };
                    value /= 10;
                }
                if (value > 0) {
                    oka[value % 10] -= 1;
                    if (oka[value % 10] < 0) {
                        t1 -= ark[v1] * 1ll;
                        continue;
                    };
                    value /= 10;
                }
                if (value > 0) {
                    oka[value % 10] -= 1;
                    if (oka[value % 10] < 0) {
                        t1 -= ark[v1] * 1ll;
                        continue;
                    };
                    value /= 10;
                }
                if (value > 0) {
                    oka[value % 10] -= 1;
                    if (oka[value % 10] < 0) {
                        t1 -= ark[v1] * 1ll;
                        continue;
                    };
                    value /= 10;
                }
                if (value > 0) {
                    oka[value % 10] -= 1;
                    if (oka[value % 10] < 0) {
                        t1 -= ark[v1] * 1ll;
                        continue;
                    };
                    value /= 10;
                }
                if (value > 0) {
                    oka[value % 10] -= 1;
                    if (oka[value % 10] < 0) {
                        t1 -= ark[v1] * 1ll;
                        continue;
                    };
                    value /= 10;
                }
                if (value > 0) {
                    oka[value % 10] -= 1;
                    if (oka[value % 10] < 0) {
                        t1 -= ark[v1] * 1ll;
                        continue;
                    };
                    value /= 10;
                }
                if (value > 0) {
                    oka[value % 10] -= 1;
                    if (oka[value % 10] < 0) {
                        t1 -= ark[v1] * 1ll;
                        continue;
                    };
                    value /= 10;
                }
                if (value > 0) {
                    oka[value % 10] -= 1;
                    if (oka[value % 10] < 0) {
                        t1 -= ark[v1] * 1ll;
                        continue;
                    };
                    value /= 10;
                }
                if (value > 0) {
                    oka[value % 10] -= 1;
                    if (oka[value % 10] < 0) {
                        t1 -= ark[v1] * 1ll;
                        continue;
                    };
                    value /= 10;
                }
                st.insert(t1);
                t1 -= ark[v1] * 1ll;
            }
            t1 -= ark[v0] * 10ll;
        }
    }
    if (hl >= 3) {
        for (int v0 = 0; v0 < l; ++v0) {
            if (!ark[v0])continue;
            t1 += ark[v0] * 100ll;
            if (t1 > nsq) {
                t1 -= ark[v0] * 100ll;
                break;
            }
            for (int v1 = 0; v1 < l; ++v1) {
                t1 += ark[v1] * 10ll;
                if (t1 > nsq) {
                    t1 -= ark[v1] * 10ll;
                    break;
                }
                if (v1 == v0) {
                    t1 -= ark[v1] * 10ll;
                    continue;
                }
                for (int v2 = 0; v2 < l; ++v2) {
                    t1 += ark[v2] * 1ll;
                    if (t1 > nsq) {
                        t1 -= ark[v2] * 1ll;
                        break;
                    }
                    if (v2 == v0) {
                        t1 -= ark[v2] * 1ll;
                        continue;
                    }
                    if (v2 == v1) {
                        t1 -= ark[v2] * 1ll;
                        continue;
                    }
                    __int64 value = t1;
                    value *= value;
                    memset(oka, 0, sizeof oka);
                    for (int i = 0; i < l; ++i)oka[ark[i]] += 1;
                    __int64 t2 = value;
                    if (value > 0) {
                        oka[value % 10] -= 1;
                        if (oka[value % 10] < 0) {
                            t1 -= ark[v2] * 1ll;
                            continue;
                        };
                        value /= 10;
                    }
                    if (value > 0) {
                        oka[value % 10] -= 1;
                        if (oka[value % 10] < 0) {
                            t1 -= ark[v2] * 1ll;
                            continue;
                        };
                        value /= 10;
                    }
                    if (value > 0) {
                        oka[value % 10] -= 1;
                        if (oka[value % 10] < 0) {
                            t1 -= ark[v2] * 1ll;
                            continue;
                        };
                        value /= 10;
                    }
                    if (value > 0) {
                        oka[value % 10] -= 1;
                        if (oka[value % 10] < 0) {
                            t1 -= ark[v2] * 1ll;
                            continue;
                        };
                        value /= 10;
                    }
                    if (value > 0) {
                        oka[value % 10] -= 1;
                        if (oka[value % 10] < 0) {
                            t1 -= ark[v2] * 1ll;
                            continue;
                        };
                        value /= 10;
                    }
                    if (value > 0) {
                        oka[value % 10] -= 1;
                        if (oka[value % 10] < 0) {
                            t1 -= ark[v2] * 1ll;
                            continue;
                        };
                        value /= 10;
                    }
                    if (value > 0) {
                        oka[value % 10] -= 1;
                        if (oka[value % 10] < 0) {
                            t1 -= ark[v2] * 1ll;
                            continue;
                        };
                        value /= 10;
                    }
                    if (value > 0) {
                        oka[value % 10] -= 1;
                        if (oka[value % 10] < 0) {
                            t1 -= ark[v2] * 1ll;
                            continue;
                        };
                        value /= 10;
                    }
                    if (value > 0) {
                        oka[value % 10] -= 1;
                        if (oka[value % 10] < 0) {
                            t1 -= ark[v2] * 1ll;
                            continue;
                        };
                        value /= 10;
                    }
                    if (value > 0) {
                        oka[value % 10] -= 1;
                        if (oka[value % 10] < 0) {
                            t1 -= ark[v2] * 1ll;
                            continue;
                        };
                        value /= 10;
                    }
                    if (value > 0) {
                        oka[value % 10] -= 1;
                        if (oka[value % 10] < 0) {
                            t1 -= ark[v2] * 1ll;
                            continue;
                        };
                        value /= 10;
                    }
                    if (value > 0) {
                        oka[value % 10] -= 1;
                        if (oka[value % 10] < 0) {
                            t1 -= ark[v2] * 1ll;
                            continue;
                        };
                        value /= 10;
                    }
                    if (value > 0) {
                        oka[value % 10] -= 1;
                        if (oka[value % 10] < 0) {
                            t1 -= ark[v2] * 1ll;
                            continue;
                        };
                        value /= 10;
                    }
                    st.insert(t1);
                    t1 -= ark[v2] * 1ll;
                }
                t1 -= ark[v1] * 10ll;
            }
            t1 -= ark[v0] * 100ll;
        }
    }
    if (hl >= 4) {
        for (int v0 = 0; v0 < l; ++v0) {
            if (!ark[v0])continue;
            t1 += ark[v0] * 1000ll;
            if (t1 > nsq) {
                t1 -= ark[v0] * 1000ll;
                break;
            }
            for (int v1 = 0; v1 < l; ++v1) {
                t1 += ark[v1] * 100ll;
                if (t1 > nsq) {
                    t1 -= ark[v1] * 100ll;
                    break;
                }
                if (v1 == v0) {
                    t1 -= ark[v1] * 100ll;
                    continue;
                }
                for (int v2 = 0; v2 < l; ++v2) {
                    t1 += ark[v2] * 10ll;
                    if (t1 > nsq) {
                        t1 -= ark[v2] * 10ll;
                        break;
                    }
                    if (v2 == v0) {
                        t1 -= ark[v2] * 10ll;
                        continue;
                    }
                    if (v2 == v1) {
                        t1 -= ark[v2] * 10ll;
                        continue;
                    }
                    for (int v3 = 0; v3 < l; ++v3) {
                        t1 += ark[v3] * 1ll;
                        if (t1 > nsq) {
                            t1 -= ark[v3] * 1ll;
                            break;
                        }
                        if (v3 == v0) {
                            t1 -= ark[v3] * 1ll;
                            continue;
                        }
                        if (v3 == v1) {
                            t1 -= ark[v3] * 1ll;
                            continue;
                        }
                        if (v3 == v2) {
                            t1 -= ark[v3] * 1ll;
                            continue;
                        }
                        __int64 value = t1;
                        value *= value;
                        memset(oka, 0, sizeof oka);
                        for (int i = 0; i < l; ++i)oka[ark[i]] += 1;
                        __int64 t2 = value;
                        if (value > 0) {
                            oka[value % 10] -= 1;
                            if (oka[value % 10] < 0) {
                                t1 -= ark[v3] * 1ll;
                                continue;
                            };
                            value /= 10;
                        }
                        if (value > 0) {
                            oka[value % 10] -= 1;
                            if (oka[value % 10] < 0) {
                                t1 -= ark[v3] * 1ll;
                                continue;
                            };
                            value /= 10;
                        }
                        if (value > 0) {
                            oka[value % 10] -= 1;
                            if (oka[value % 10] < 0) {
                                t1 -= ark[v3] * 1ll;
                                continue;
                            };
                            value /= 10;
                        }
                        if (value > 0) {
                            oka[value % 10] -= 1;
                            if (oka[value % 10] < 0) {
                                t1 -= ark[v3] * 1ll;
                                continue;
                            };
                            value /= 10;
                        }
                        if (value > 0) {
                            oka[value % 10] -= 1;
                            if (oka[value % 10] < 0) {
                                t1 -= ark[v3] * 1ll;
                                continue;
                            };
                            value /= 10;
                        }
                        if (value > 0) {
                            oka[value % 10] -= 1;
                            if (oka[value % 10] < 0) {
                                t1 -= ark[v3] * 1ll;
                                continue;
                            };
                            value /= 10;
                        }
                        if (value > 0) {
                            oka[value % 10] -= 1;
                            if (oka[value % 10] < 0) {
                                t1 -= ark[v3] * 1ll;
                                continue;
                            };
                            value /= 10;
                        }
                        if (value > 0) {
                            oka[value % 10] -= 1;
                            if (oka[value % 10] < 0) {
                                t1 -= ark[v3] * 1ll;
                                continue;
                            };
                            value /= 10;
                        }
                        if (value > 0) {
                            oka[value % 10] -= 1;
                            if (oka[value % 10] < 0) {
                                t1 -= ark[v3] * 1ll;
                                continue;
                            };
                            value /= 10;
                        }
                        if (value > 0) {
                            oka[value % 10] -= 1;
                            if (oka[value % 10] < 0) {
                                t1 -= ark[v3] * 1ll;
                                continue;
                            };
                            value /= 10;
                        }
                        if (value > 0) {
                            oka[value % 10] -= 1;
                            if (oka[value % 10] < 0) {
                                t1 -= ark[v3] * 1ll;
                                continue;
                            };
                            value /= 10;
                        }
                        if (value > 0) {
                            oka[value % 10] -= 1;
                            if (oka[value % 10] < 0) {
                                t1 -= ark[v3] * 1ll;
                                continue;
                            };
                            value /= 10;
                        }
                        if (value > 0) {
                            oka[value % 10] -= 1;
                            if (oka[value % 10] < 0) {
                                t1 -= ark[v3] * 1ll;
                                continue;
                            };
                            value /= 10;
                        }
                        st.insert(t1);
                        t1 -= ark[v3] * 1ll;
                    }
                    t1 -= ark[v2] * 10ll;
                }
                t1 -= ark[v1] * 100ll;
            }
            t1 -= ark[v0] * 1000ll;
        }
    }
    if (hl >= 5) {
        for (int v0 = 0; v0 < l; ++v0) {
            if (!ark[v0])continue;
            t1 += ark[v0] * 10000ll;
            if (t1 > nsq) {
                t1 -= ark[v0] * 10000ll;
                break;
            }
            for (int v1 = 0; v1 < l; ++v1) {
                t1 += ark[v1] * 1000ll;
                if (t1 > nsq) {
                    t1 -= ark[v1] * 1000ll;
                    break;
                }
                if (v1 == v0) {
                    t1 -= ark[v1] * 1000ll;
                    continue;
                }
                for (int v2 = 0; v2 < l; ++v2) {
                    t1 += ark[v2] * 100ll;
                    if (t1 > nsq) {
                        t1 -= ark[v2] * 100ll;
                        break;
                    }
                    if (v2 == v0) {
                        t1 -= ark[v2] * 100ll;
                        continue;
                    }
                    if (v2 == v1) {
                        t1 -= ark[v2] * 100ll;
                        continue;
                    }
                    for (int v3 = 0; v3 < l; ++v3) {
                        t1 += ark[v3] * 10ll;
                        if (t1 > nsq) {
                            t1 -= ark[v3] * 10ll;
                            break;
                        }
                        if (v3 == v0) {
                            t1 -= ark[v3] * 10ll;
                            continue;
                        }
                        if (v3 == v1) {
                            t1 -= ark[v3] * 10ll;
                            continue;
                        }
                        if (v3 == v2) {
                            t1 -= ark[v3] * 10ll;
                            continue;
                        }
                        for (int v4 = 0; v4 < l; ++v4) {
                            t1 += ark[v4] * 1ll;
                            if (t1 > nsq) {
                                t1 -= ark[v4] * 1ll;
                                break;
                            }
                            if (v4 == v0) {
                                t1 -= ark[v4] * 1ll;
                                continue;
                            }
                            if (v4 == v1) {
                                t1 -= ark[v4] * 1ll;
                                continue;
                            }
                            if (v4 == v2) {
                                t1 -= ark[v4] * 1ll;
                                continue;
                            }
                            if (v4 == v3) {
                                t1 -= ark[v4] * 1ll;
                                continue;
                            }
                            __int64 value = t1;
                            value *= value;
                            memset(oka, 0, sizeof oka);
                            for (int i = 0; i < l; ++i)oka[ark[i]] += 1;
                            __int64 t2 = value;
                            if (value > 0) {
                                oka[value % 10] -= 1;
                                if (oka[value % 10] < 0) {
                                    t1 -= ark[v4] * 1ll;
                                    continue;
                                };
                                value /= 10;
                            }
                            if (value > 0) {
                                oka[value % 10] -= 1;
                                if (oka[value % 10] < 0) {
                                    t1 -= ark[v4] * 1ll;
                                    continue;
                                };
                                value /= 10;
                            }
                            if (value > 0) {
                                oka[value % 10] -= 1;
                                if (oka[value % 10] < 0) {
                                    t1 -= ark[v4] * 1ll;
                                    continue;
                                };
                                value /= 10;
                            }
                            if (value > 0) {
                                oka[value % 10] -= 1;
                                if (oka[value % 10] < 0) {
                                    t1 -= ark[v4] * 1ll;
                                    continue;
                                };
                                value /= 10;
                            }
                            if (value > 0) {
                                oka[value % 10] -= 1;
                                if (oka[value % 10] < 0) {
                                    t1 -= ark[v4] * 1ll;
                                    continue;
                                };
                                value /= 10;
                            }
                            if (value > 0) {
                                oka[value % 10] -= 1;
                                if (oka[value % 10] < 0) {
                                    t1 -= ark[v4] * 1ll;
                                    continue;
                                };
                                value /= 10;
                            }
                            if (value > 0) {
                                oka[value % 10] -= 1;
                                if (oka[value % 10] < 0) {
                                    t1 -= ark[v4] * 1ll;
                                    continue;
                                };
                                value /= 10;
                            }
                            if (value > 0) {
                                oka[value % 10] -= 1;
                                if (oka[value % 10] < 0) {
                                    t1 -= ark[v4] * 1ll;
                                    continue;
                                };
                                value /= 10;
                            }
                            if (value > 0) {
                                oka[value % 10] -= 1;
                                if (oka[value % 10] < 0) {
                                    t1 -= ark[v4] * 1ll;
                                    continue;
                                };
                                value /= 10;
                            }
                            if (value > 0) {
                                oka[value % 10] -= 1;
                                if (oka[value % 10] < 0) {
                                    t1 -= ark[v4] * 1ll;
                                    continue;
                                };
                                value /= 10;
                            }
                            if (value > 0) {
                                oka[value % 10] -= 1;
                                if (oka[value % 10] < 0) {
                                    t1 -= ark[v4] * 1ll;
                                    continue;
                                };
                                value /= 10;
                            }
                            if (value > 0) {
                                oka[value % 10] -= 1;
                                if (oka[value % 10] < 0) {
                                    t1 -= ark[v4] * 1ll;
                                    continue;
                                };
                                value /= 10;
                            }
                            if (value > 0) {
                                oka[value % 10] -= 1;
                                if (oka[value % 10] < 0) {
                                    t1 -= ark[v4] * 1ll;
                                    continue;
                                };
                                value /= 10;
                            }
                            st.insert(t1);
                            t1 -= ark[v4] * 1ll;
                        }
                        t1 -= ark[v3] * 10ll;
                    }
                    t1 -= ark[v2] * 100ll;
                }
                t1 -= ark[v1] * 1000ll;
            }
            t1 -= ark[v0] * 10000ll;
        }
    }
    if (hl >= 6) {
        for (int v0 = 0; v0 < l; ++v0) {
            if (!ark[v0])continue;
            t1 += ark[v0] * 100000ll;
            if (t1 > nsq) {
                t1 -= ark[v0] * 100000ll;
                break;
            }
            for (int v1 = 0; v1 < l; ++v1) {
                t1 += ark[v1] * 10000ll;
                if (t1 > nsq) {
                    t1 -= ark[v1] * 10000ll;
                    break;
                }
                if (v1 == v0) {
                    t1 -= ark[v1] * 10000ll;
                    continue;
                }
                for (int v2 = 0; v2 < l; ++v2) {
                    t1 += ark[v2] * 1000ll;
                    if (t1 > nsq) {
                        t1 -= ark[v2] * 1000ll;
                        break;
                    }
                    if (v2 == v0) {
                        t1 -= ark[v2] * 1000ll;
                        continue;
                    }
                    if (v2 == v1) {
                        t1 -= ark[v2] * 1000ll;
                        continue;
                    }
                    for (int v3 = 0; v3 < l; ++v3) {
                        t1 += ark[v3] * 100ll;
                        if (t1 > nsq) {
                            t1 -= ark[v3] * 100ll;
                            break;
                        }
                        if (v3 == v0) {
                            t1 -= ark[v3] * 100ll;
                            continue;
                        }
                        if (v3 == v1) {
                            t1 -= ark[v3] * 100ll;
                            continue;
                        }
                        if (v3 == v2) {
                            t1 -= ark[v3] * 100ll;
                            continue;
                        }
                        for (int v4 = 0; v4 < l; ++v4) {
                            t1 += ark[v4] * 10ll;
                            if (t1 > nsq) {
                                t1 -= ark[v4] * 10ll;
                                break;
                            }
                            if (v4 == v0) {
                                t1 -= ark[v4] * 10ll;
                                continue;
                            }
                            if (v4 == v1) {
                                t1 -= ark[v4] * 10ll;
                                continue;
                            }
                            if (v4 == v2) {
                                t1 -= ark[v4] * 10ll;
                                continue;
                            }
                            if (v4 == v3) {
                                t1 -= ark[v4] * 10ll;
                                continue;
                            }
                            for (int v5 = 0; v5 < l; ++v5) {
                                t1 += ark[v5] * 1ll;
                                if (t1 > nsq) {
                                    t1 -= ark[v5] * 1ll;
                                    break;
                                }
                                if (v5 == v0) {
                                    t1 -= ark[v5] * 1ll;
                                    continue;
                                }
                                if (v5 == v1) {
                                    t1 -= ark[v5] * 1ll;
                                    continue;
                                }
                                if (v5 == v2) {
                                    t1 -= ark[v5] * 1ll;
                                    continue;
                                }
                                if (v5 == v3) {
                                    t1 -= ark[v5] * 1ll;
                                    continue;
                                }
                                if (v5 == v4) {
                                    t1 -= ark[v5] * 1ll;
                                    continue;
                                }
                                __int64 value = t1;
                                value *= value;
                                memset(oka, 0, sizeof oka);
                                for (int i = 0; i < l; ++i)oka[ark[i]] += 1;
                                __int64 t2 = value;
                                if (value > 0) {
                                    oka[value % 10] -= 1;
                                    if (oka[value % 10] < 0) {
                                        t1 -= ark[v5] * 1ll;
                                        continue;
                                    };
                                    value /= 10;
                                }
                                if (value > 0) {
                                    oka[value % 10] -= 1;
                                    if (oka[value % 10] < 0) {
                                        t1 -= ark[v5] * 1ll;
                                        continue;
                                    };
                                    value /= 10;
                                }
                                if (value > 0) {
                                    oka[value % 10] -= 1;
                                    if (oka[value % 10] < 0) {
                                        t1 -= ark[v5] * 1ll;
                                        continue;
                                    };
                                    value /= 10;
                                }
                                if (value > 0) {
                                    oka[value % 10] -= 1;
                                    if (oka[value % 10] < 0) {
                                        t1 -= ark[v5] * 1ll;
                                        continue;
                                    };
                                    value /= 10;
                                }
                                if (value > 0) {
                                    oka[value % 10] -= 1;
                                    if (oka[value % 10] < 0) {
                                        t1 -= ark[v5] * 1ll;
                                        continue;
                                    };
                                    value /= 10;
                                }
                                if (value > 0) {
                                    oka[value % 10] -= 1;
                                    if (oka[value % 10] < 0) {
                                        t1 -= ark[v5] * 1ll;
                                        continue;
                                    };
                                    value /= 10;
                                }
                                if (value > 0) {
                                    oka[value % 10] -= 1;
                                    if (oka[value % 10] < 0) {
                                        t1 -= ark[v5] * 1ll;
                                        continue;
                                    };
                                    value /= 10;
                                }
                                if (value > 0) {
                                    oka[value % 10] -= 1;
                                    if (oka[value % 10] < 0) {
                                        t1 -= ark[v5] * 1ll;
                                        continue;
                                    };
                                    value /= 10;
                                }
                                if (value > 0) {
                                    oka[value % 10] -= 1;
                                    if (oka[value % 10] < 0) {
                                        t1 -= ark[v5] * 1ll;
                                        continue;
                                    };
                                    value /= 10;
                                }
                                if (value > 0) {
                                    oka[value % 10] -= 1;
                                    if (oka[value % 10] < 0) {
                                        t1 -= ark[v5] * 1ll;
                                        continue;
                                    };
                                    value /= 10;
                                }
                                if (value > 0) {
                                    oka[value % 10] -= 1;
                                    if (oka[value % 10] < 0) {
                                        t1 -= ark[v5] * 1ll;
                                        continue;
                                    };
                                    value /= 10;
                                }
                                if (value > 0) {
                                    oka[value % 10] -= 1;
                                    if (oka[value % 10] < 0) {
                                        t1 -= ark[v5] * 1ll;
                                        continue;
                                    };
                                    value /= 10;
                                }
                                if (value > 0) {
                                    oka[value % 10] -= 1;
                                    if (oka[value % 10] < 0) {
                                        t1 -= ark[v5] * 1ll;
                                        continue;
                                    };
                                    value /= 10;
                                }
                                st.insert(t1);
                                t1 -= ark[v5] * 1ll;
                            }
                            t1 -= ark[v4] * 10ll;
                        }
                        t1 -= ark[v3] * 100ll;
                    }
                    t1 -= ark[v2] * 1000ll;
                }
                t1 -= ark[v1] * 10000ll;
            }
            t1 -= ark[v0] * 100000ll;
        }
    }
    if (hl >= 7) {
        for (int v0 = 0; v0 < l; ++v0) {
            if (!ark[v0])continue;
            t1 += ark[v0] * 1000000ll;
            if (t1 > nsq) {
                t1 -= ark[v0] * 1000000ll;
                break;
            }
            for (int v1 = 0; v1 < l; ++v1) {
                t1 += ark[v1] * 100000ll;
                if (t1 > nsq) {
                    t1 -= ark[v1] * 100000ll;
                    break;
                }
                if (v1 == v0) {
                    t1 -= ark[v1] * 100000ll;
                    continue;
                }
                for (int v2 = 0; v2 < l; ++v2) {
                    t1 += ark[v2] * 10000ll;
                    if (t1 > nsq) {
                        t1 -= ark[v2] * 10000ll;
                        break;
                    }
                    if (v2 == v0) {
                        t1 -= ark[v2] * 10000ll;
                        continue;
                    }
                    if (v2 == v1) {
                        t1 -= ark[v2] * 10000ll;
                        continue;
                    }
                    for (int v3 = 0; v3 < l; ++v3) {
                        t1 += ark[v3] * 1000ll;
                        if (t1 > nsq) {
                            t1 -= ark[v3] * 1000ll;
                            break;
                        }
                        if (v3 == v0) {
                            t1 -= ark[v3] * 1000ll;
                            continue;
                        }
                        if (v3 == v1) {
                            t1 -= ark[v3] * 1000ll;
                            continue;
                        }
                        if (v3 == v2) {
                            t1 -= ark[v3] * 1000ll;
                            continue;
                        }
                        for (int v4 = 0; v4 < l; ++v4) {
                            t1 += ark[v4] * 100ll;
                            if (t1 > nsq) {
                                t1 -= ark[v4] * 100ll;
                                break;
                            }
                            if (v4 == v0) {
                                t1 -= ark[v4] * 100ll;
                                continue;
                            }
                            if (v4 == v1) {
                                t1 -= ark[v4] * 100ll;
                                continue;
                            }
                            if (v4 == v2) {
                                t1 -= ark[v4] * 100ll;
                                continue;
                            }
                            if (v4 == v3) {
                                t1 -= ark[v4] * 100ll;
                                continue;
                            }
                            for (int v5 = 0; v5 < l; ++v5) {
                                t1 += ark[v5] * 10ll;
                                if (t1 > nsq) {
                                    t1 -= ark[v5] * 10ll;
                                    break;
                                }
                                if (v5 == v0) {
                                    t1 -= ark[v5] * 10ll;
                                    continue;
                                }
                                if (v5 == v1) {
                                    t1 -= ark[v5] * 10ll;
                                    continue;
                                }
                                if (v5 == v2) {
                                    t1 -= ark[v5] * 10ll;
                                    continue;
                                }
                                if (v5 == v3) {
                                    t1 -= ark[v5] * 10ll;
                                    continue;
                                }
                                if (v5 == v4) {
                                    t1 -= ark[v5] * 10ll;
                                    continue;
                                }
                                for (int v6 = 0; v6 < l; ++v6) {
                                    t1 += ark[v6] * 1ll;
                                    if (t1 > nsq) {
                                        t1 -= ark[v6] * 1ll;
                                        break;
                                    }
                                    if (v6 == v0) {
                                        t1 -= ark[v6] * 1ll;
                                        continue;
                                    }
                                    if (v6 == v1) {
                                        t1 -= ark[v6] * 1ll;
                                        continue;
                                    }
                                    if (v6 == v2) {
                                        t1 -= ark[v6] * 1ll;
                                        continue;
                                    }
                                    if (v6 == v3) {
                                        t1 -= ark[v6] * 1ll;
                                        continue;
                                    }
                                    if (v6 == v4) {
                                        t1 -= ark[v6] * 1ll;
                                        continue;
                                    }
                                    if (v6 == v5) {
                                        t1 -= ark[v6] * 1ll;
                                        continue;
                                    }
                                    __int64 value = t1;
                                    value *= value;
                                    memset(oka, 0, sizeof oka);
                                    for (int i = 0; i < l; ++i)oka[ark[i]] += 1;
                                    __int64 t2 = value;
                                    if (value > 0) {
                                        oka[value % 10] -= 1;
                                        if (oka[value % 10] < 0) {
                                            t1 -= ark[v6] * 1ll;
                                            continue;
                                        };
                                        value /= 10;
                                    }
                                    if (value > 0) {
                                        oka[value % 10] -= 1;
                                        if (oka[value % 10] < 0) {
                                            t1 -= ark[v6] * 1ll;
                                            continue;
                                        };
                                        value /= 10;
                                    }
                                    if (value > 0) {
                                        oka[value % 10] -= 1;
                                        if (oka[value % 10] < 0) {
                                            t1 -= ark[v6] * 1ll;
                                            continue;
                                        };
                                        value /= 10;
                                    }
                                    if (value > 0) {
                                        oka[value % 10] -= 1;
                                        if (oka[value % 10] < 0) {
                                            t1 -= ark[v6] * 1ll;
                                            continue;
                                        };
                                        value /= 10;
                                    }
                                    if (value > 0) {
                                        oka[value % 10] -= 1;
                                        if (oka[value % 10] < 0) {
                                            t1 -= ark[v6] * 1ll;
                                            continue;
                                        };
                                        value /= 10;
                                    }
                                    if (value > 0) {
                                        oka[value % 10] -= 1;
                                        if (oka[value % 10] < 0) {
                                            t1 -= ark[v6] * 1ll;
                                            continue;
                                        };
                                        value /= 10;
                                    }
                                    if (value > 0) {
                                        oka[value % 10] -= 1;
                                        if (oka[value % 10] < 0) {
                                            t1 -= ark[v6] * 1ll;
                                            continue;
                                        };
                                        value /= 10;
                                    }
                                    if (value > 0) {
                                        oka[value % 10] -= 1;
                                        if (oka[value % 10] < 0) {
                                            t1 -= ark[v6] * 1ll;
                                            continue;
                                        };
                                        value /= 10;
                                    }
                                    if (value > 0) {
                                        oka[value % 10] -= 1;
                                        if (oka[value % 10] < 0) {
                                            t1 -= ark[v6] * 1ll;
                                            continue;
                                        };
                                        value /= 10;
                                    }
                                    if (value > 0) {
                                        oka[value % 10] -= 1;
                                        if (oka[value % 10] < 0) {
                                            t1 -= ark[v6] * 1ll;
                                            continue;
                                        };
                                        value /= 10;
                                    }
                                    if (value > 0) {
                                        oka[value % 10] -= 1;
                                        if (oka[value % 10] < 0) {
                                            t1 -= ark[v6] * 1ll;
                                            continue;
                                        };
                                        value /= 10;
                                    }
                                    if (value > 0) {
                                        oka[value % 10] -= 1;
                                        if (oka[value % 10] < 0) {
                                            t1 -= ark[v6] * 1ll;
                                            continue;
                                        };
                                        value /= 10;
                                    }
                                    if (value > 0) {
                                        oka[value % 10] -= 1;
                                        if (oka[value % 10] < 0) {
                                            t1 -= ark[v6] * 1ll;
                                            continue;
                                        };
                                        value /= 10;
                                    }
                                    st.insert(t1);
                                    t1 -= ark[v6] * 1ll;
                                }
                                t1 -= ark[v5] * 10ll;
                            }
                            t1 -= ark[v4] * 100ll;
                        }
                        t1 -= ark[v3] * 1000ll;
                    }
                    t1 -= ark[v2] * 10000ll;
                }
                t1 -= ark[v1] * 100000ll;
            }
            t1 -= ark[v0] * 1000000ll;
        }
    }
    if (hl >= 8) {
        for (int v0 = 0; v0 < l; ++v0) {
            if (!ark[v0])continue;
            t1 += ark[v0] * 10000000ll;
            if (t1 > nsq) {
                t1 -= ark[v0] * 10000000ll;
                break;
            }
            for (int v1 = 0; v1 < l; ++v1) {
                t1 += ark[v1] * 1000000ll;
                if (t1 > nsq) {
                    t1 -= ark[v1] * 1000000ll;
                    break;
                }
                if (v1 == v0) {
                    t1 -= ark[v1] * 1000000ll;
                    continue;
                }
                for (int v2 = 0; v2 < l; ++v2) {
                    t1 += ark[v2] * 100000ll;
                    if (t1 > nsq) {
                        t1 -= ark[v2] * 100000ll;
                        break;
                    }
                    if (v2 == v0) {
                        t1 -= ark[v2] * 100000ll;
                        continue;
                    }
                    if (v2 == v1) {
                        t1 -= ark[v2] * 100000ll;
                        continue;
                    }
                    for (int v3 = 0; v3 < l; ++v3) {
                        t1 += ark[v3] * 10000ll;
                        if (t1 > nsq) {
                            t1 -= ark[v3] * 10000ll;
                            break;
                        }
                        if (v3 == v0) {
                            t1 -= ark[v3] * 10000ll;
                            continue;
                        }
                        if (v3 == v1) {
                            t1 -= ark[v3] * 10000ll;
                            continue;
                        }
                        if (v3 == v2) {
                            t1 -= ark[v3] * 10000ll;
                            continue;
                        }
                        for (int v4 = 0; v4 < l; ++v4) {
                            t1 += ark[v4] * 1000ll;
                            if (t1 > nsq) {
                                t1 -= ark[v4] * 1000ll;
                                break;
                            }
                            if (v4 == v0) {
                                t1 -= ark[v4] * 1000ll;
                                continue;
                            }
                            if (v4 == v1) {
                                t1 -= ark[v4] * 1000ll;
                                continue;
                            }
                            if (v4 == v2) {
                                t1 -= ark[v4] * 1000ll;
                                continue;
                            }
                            if (v4 == v3) {
                                t1 -= ark[v4] * 1000ll;
                                continue;
                            }
                            for (int v5 = 0; v5 < l; ++v5) {
                                t1 += ark[v5] * 100ll;
                                if (t1 > nsq) {
                                    t1 -= ark[v5] * 100ll;
                                    break;
                                }
                                if (v5 == v0) {
                                    t1 -= ark[v5] * 100ll;
                                    continue;
                                }
                                if (v5 == v1) {
                                    t1 -= ark[v5] * 100ll;
                                    continue;
                                }
                                if (v5 == v2) {
                                    t1 -= ark[v5] * 100ll;
                                    continue;
                                }
                                if (v5 == v3) {
                                    t1 -= ark[v5] * 100ll;
                                    continue;
                                }
                                if (v5 == v4) {
                                    t1 -= ark[v5] * 100ll;
                                    continue;
                                }
                                for (int v6 = 0; v6 < l; ++v6) {
                                    t1 += ark[v6] * 10ll;
                                    if (t1 > nsq) {
                                        t1 -= ark[v6] * 10ll;
                                        break;
                                    }
                                    if (v6 == v0) {
                                        t1 -= ark[v6] * 10ll;
                                        continue;
                                    }
                                    if (v6 == v1) {
                                        t1 -= ark[v6] * 10ll;
                                        continue;
                                    }
                                    if (v6 == v2) {
                                        t1 -= ark[v6] * 10ll;
                                        continue;
                                    }
                                    if (v6 == v3) {
                                        t1 -= ark[v6] * 10ll;
                                        continue;
                                    }
                                    if (v6 == v4) {
                                        t1 -= ark[v6] * 10ll;
                                        continue;
                                    }
                                    if (v6 == v5) {
                                        t1 -= ark[v6] * 10ll;
                                        continue;
                                    }
                                    for (int v7 = 0; v7 < l; ++v7) {
                                        t1 += ark[v7] * 1ll;
                                        if (t1 > nsq) {
                                            t1 -= ark[v7] * 1ll;
                                            break;
                                        }
                                        if (v7 == v0) {
                                            t1 -= ark[v7] * 1ll;
                                            continue;
                                        }
                                        if (v7 == v1) {
                                            t1 -= ark[v7] * 1ll;
                                            continue;
                                        }
                                        if (v7 == v2) {
                                            t1 -= ark[v7] * 1ll;
                                            continue;
                                        }
                                        if (v7 == v3) {
                                            t1 -= ark[v7] * 1ll;
                                            continue;
                                        }
                                        if (v7 == v4) {
                                            t1 -= ark[v7] * 1ll;
                                            continue;
                                        }
                                        if (v7 == v5) {
                                            t1 -= ark[v7] * 1ll;
                                            continue;
                                        }
                                        if (v7 == v6) {
                                            t1 -= ark[v7] * 1ll;
                                            continue;
                                        }
                                        __int64 value = t1;
                                        value *= value;
                                        memset(oka, 0, sizeof oka);
                                        for (int i = 0; i < l; ++i)oka[ark[i]] += 1;
                                        __int64 t2 = value;
                                        if (value > 0) {
                                            oka[value % 10] -= 1;
                                            if (oka[value % 10] < 0) {
                                                t1 -= ark[v7] * 1ll;
                                                continue;
                                            };
                                            value /= 10;
                                        }
                                        if (value > 0) {
                                            oka[value % 10] -= 1;
                                            if (oka[value % 10] < 0) {
                                                t1 -= ark[v7] * 1ll;
                                                continue;
                                            };
                                            value /= 10;
                                        }
                                        if (value > 0) {
                                            oka[value % 10] -= 1;
                                            if (oka[value % 10] < 0) {
                                                t1 -= ark[v7] * 1ll;
                                                continue;
                                            };
                                            value /= 10;
                                        }
                                        if (value > 0) {
                                            oka[value % 10] -= 1;
                                            if (oka[value % 10] < 0) {
                                                t1 -= ark[v7] * 1ll;
                                                continue;
                                            };
                                            value /= 10;
                                        }
                                        if (value > 0) {
                                            oka[value % 10] -= 1;
                                            if (oka[value % 10] < 0) {
                                                t1 -= ark[v7] * 1ll;
                                                continue;
                                            };
                                            value /= 10;
                                        }
                                        if (value > 0) {
                                            oka[value % 10] -= 1;
                                            if (oka[value % 10] < 0) {
                                                t1 -= ark[v7] * 1ll;
                                                continue;
                                            };
                                            value /= 10;
                                        }
                                        if (value > 0) {
                                            oka[value % 10] -= 1;
                                            if (oka[value % 10] < 0) {
                                                t1 -= ark[v7] * 1ll;
                                                continue;
                                            };
                                            value /= 10;
                                        }
                                        if (value > 0) {
                                            oka[value % 10] -= 1;
                                            if (oka[value % 10] < 0) {
                                                t1 -= ark[v7] * 1ll;
                                                continue;
                                            };
                                            value /= 10;
                                        }
                                        if (value > 0) {
                                            oka[value % 10] -= 1;
                                            if (oka[value % 10] < 0) {
                                                t1 -= ark[v7] * 1ll;
                                                continue;
                                            };
                                            value /= 10;
                                        }
                                        if (value > 0) {
                                            oka[value % 10] -= 1;
                                            if (oka[value % 10] < 0) {
                                                t1 -= ark[v7] * 1ll;
                                                continue;
                                            };
                                            value /= 10;
                                        }
                                        if (value > 0) {
                                            oka[value % 10] -= 1;
                                            if (oka[value % 10] < 0) {
                                                t1 -= ark[v7] * 1ll;
                                                continue;
                                            };
                                            value /= 10;
                                        }
                                        if (value > 0) {
                                            oka[value % 10] -= 1;
                                            if (oka[value % 10] < 0) {
                                                t1 -= ark[v7] * 1ll;
                                                continue;
                                            };
                                            value /= 10;
                                        }
                                        if (value > 0) {
                                            oka[value % 10] -= 1;
                                            if (oka[value % 10] < 0) {
                                                t1 -= ark[v7] * 1ll;
                                                continue;
                                            };
                                            value /= 10;
                                        }
                                        st.insert(t1);
                                        t1 -= ark[v7] * 1ll;
                                    }
                                    t1 -= ark[v6] * 10ll;
                                }
                                t1 -= ark[v5] * 100ll;
                            }
                            t1 -= ark[v4] * 1000ll;
                        }
                        t1 -= ark[v3] * 10000ll;
                    }
                    t1 -= ark[v2] * 100000ll;
                }
                t1 -= ark[v1] * 1000000ll;
            }
            t1 -= ark[v0] * 10000000ll;
        }
    }




    //

    cout << "Hidden squares in " << norig << endl;
    for (auto i:st) {
        cout << i << " * " << i << " = " << (i * i) << endl;
    }

}


int main() {

#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);

#else
                                                                                                                            //freopen("scrivener.in", "r", stdin);
    //freopen("scrivener.out", "w", stdout);
#endif
    char kek[1600000];
    cin.read(kek, 1600000);
    while (!isdigit(kek[strlen(kek) - 1])) {
        kek[strlen(kek) - 1] = 0;
    }
    kek[strlen(kek) - 1] = 0;
    kek[strlen(kek) - 1] = 0;
    stringstream in(kek);

    in >> n1;
    int keka = 0;

    while (n1 != -1) {


        if (keka)
            cout << endl;
        n = to_string(n1);
        string bign = n;
        sort(bign.begin(), bign.end());
        reverse(bign.begin(), bign.end());
        stringstream kekasmemas(bign);
        kekasmemas>>n1;
        solve();
        keka = 1;

        if (in.eof())
            n1 = -1;
        else
            in >> n1;

    }
    return 0;
}