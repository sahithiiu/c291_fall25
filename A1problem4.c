// A1problem4.c
#include <stdio.h>
#include <ctype.h>

static double tax_after(double income, int married) {
    if (married) {
        return income > 32000.0 ? income * 0.75 : income * 0.90;
    } else {
        return income > 64000.0 ? income * 0.75 : income * 0.90;
    }
}

int main(void) {
    char type;
    if (scanf(" %c", &type) != 1) return 0;
    type = toupper(type);

    double annual_before = 0.0;
    int warn = 0;
    double hourly_rate = 0.0;

    if (type == 'A') {
        double monthly;
        if (scanf("%lf", &monthly) != 1) return 0;
        if (monthly < 0) { printf("Error: Salary cannot be negative."); return 0; }
        annual_before = 12.0 * monthly;
    } else if (type == 'S') {
        double monthly; int otm;
        if (scanf("%lf %d", &monthly, &otm) != 2) return 0;
        if (monthly < 0) { printf("Error: Salary cannot be negative."); return 0; }
        if (otm < 0) { printf("Error: Overtime hours cannot be negative."); return 0; }
        if (otm > 10) { otm = 10; warn = 1; }
        hourly_rate = monthly / (20.0 * 8.0); // 160 hrs/mo
        double ot_pay_m = otm * hourly_rate * 1.5;
        annual_before = 12.0 * (monthly + ot_pay_m);
    } else if (type == 'E') {
        double monthly; int ot_per_day; char vac;
        int sold;
        if (scanf("%lf %d %c %d", &monthly, &ot_per_day, &vac, &sold) != 4) return 0;
        if (monthly < 0) { printf("Error: Salary cannot be negative."); return 0; }
        if (ot_per_day < 0) { printf("Error: Overtime hours cannot be negative."); return 0; }
        if (sold < 0) { printf("Error: Products sold cannot be negative."); return 0; }
        vac = tolower(vac);
        if (ot_per_day > 1) { ot_per_day = 1; warn = 1; } // implicit cap note (no message in spec but safe)
        hourly_rate = monthly / (20.0 * 8.0);
        int months_work = (vac == 'y') ? 11 : 12;
        double ot_pay_m = (ot_per_day * 20.0) * hourly_rate * 1.35;
        double salary_total = months_work * monthly + ((vac == 'y') ? 0.5 * monthly : 0.0);
        annual_before = salary_total + months_work * ot_pay_m + 600.0 * sold;
    } else if (type == 'P') {
        double weekly; int otw; int sold;
        if (scanf("%lf %d %d", &weekly, &otw, &sold) != 3) return 0;
        if (weekly < 0) { printf("Error: Salary cannot be negative."); return 0; }
        if (otw < 0) { printf("Error: Overtime hours cannot be negative."); return 0; }
        if (sold < 0) { printf("Error: Products sold cannot be negative."); return 0; }
        if (otw > 10) { otw = 10; warn = 1; }
        // Assume 40 normal hours/week (20 days/mo * 8 h / 4 weeks = 40), so hourly rate:
        double hourly = weekly / 40.0;
        double week_total = weekly + otw * hourly * 1.0;
        annual_before = 48.0 * week_total + 600.0 * sold;
    } else if (type == 'H') {
        double hourly; int total_week_hours;
        if (scanf("%lf %d", &hourly, &total_week_hours) != 2) return 0;
        if (hourly < 0) { printf("Error: Salary cannot be negative."); return 0; }
        if (total_week_hours < 0) { printf("Error: Overtime hours cannot be negative."); return 0; }
        int normal = total_week_hours < 10 ? total_week_hours : 10;
        int overtime = total_week_hours - normal;
        if (overtime < 0) overtime = 0;
        if (overtime > 10) { overtime = 10; warn = 1; }
        double week_total = normal * hourly + overtime * hourly * 1.25;
        annual_before = 48.0 * week_total;
    } else {
        return 0; // unspecified type
    }

    int married = 0;
    // Some branches already consumed many tokens; just read one y/n now
    {
        char ans;
        if (scanf(" %c", &ans) == 1) married = (tolower(ans) == 'y');
    }

    if (warn) {
        // Match the example text for exceeded overtime in monthly staff case (cap varies by type)
        // We'll compute the cap and print that number.
        if (type == 'S') {
            printf("Overtime hours exceed limit. Only 10 hours will be counted.\n");
        } else if (type == 'E') {
            printf("Overtime hours exceed limit. Only 1 hours will be counted.\n");
        } else if (type == 'P' || type == 'H') {
            printf("Overtime hours exceed limit. Only 10 hours will be counted.\n");
        }
    }

    double after = tax_after(annual_before, married);
    printf("This employee's annual income is $%.2f before tax and $%.2f after tax.", annual_before, after);
    return 0;
}
