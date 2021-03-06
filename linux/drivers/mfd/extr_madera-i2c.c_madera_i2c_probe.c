#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct regmap_config {int dummy; } ;
struct madera {unsigned long type; char const* type_name; int /*<<< orphan*/  irq; int /*<<< orphan*/ * dev; void* regmap_32bit; void* regmap; } ;
struct i2c_device_id {unsigned long driver_data; } ;
struct i2c_client {int /*<<< orphan*/  irq; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_MFD_CS47L15 ; 
 int /*<<< orphan*/  CONFIG_MFD_CS47L35 ; 
 int /*<<< orphan*/  CONFIG_MFD_CS47L85 ; 
 int /*<<< orphan*/  CONFIG_MFD_CS47L90 ; 
 int /*<<< orphan*/  CONFIG_MFD_CS47L92 ; 
#define  CS42L92 136 
#define  CS47L15 135 
#define  CS47L35 134 
#define  CS47L85 133 
#define  CS47L90 132 
#define  CS47L91 131 
#define  CS47L92 130 
#define  CS47L93 129 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IS_ENABLED (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
#define  WM1840 128 
 struct regmap_config cs47l15_16bit_i2c_regmap ; 
 struct regmap_config cs47l15_32bit_i2c_regmap ; 
 struct regmap_config cs47l35_16bit_i2c_regmap ; 
 struct regmap_config cs47l35_32bit_i2c_regmap ; 
 struct regmap_config cs47l85_16bit_i2c_regmap ; 
 struct regmap_config cs47l85_32bit_i2c_regmap ; 
 struct regmap_config cs47l90_16bit_i2c_regmap ; 
 struct regmap_config cs47l90_32bit_i2c_regmap ; 
 struct regmap_config cs47l92_16bit_i2c_regmap ; 
 struct regmap_config cs47l92_32bit_i2c_regmap ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct madera* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 void* devm_regmap_init_i2c (struct i2c_client*,struct regmap_config const*) ; 
 int madera_dev_init (struct madera*) ; 
 char* madera_name_from_type (unsigned long) ; 
 void* of_device_get_match_data (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int madera_i2c_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *id)
{
	struct madera *madera;
	const struct regmap_config *regmap_16bit_config = NULL;
	const struct regmap_config *regmap_32bit_config = NULL;
	const void *of_data;
	unsigned long type;
	const char *name;
	int ret;

	of_data = of_device_get_match_data(&i2c->dev);
	if (of_data)
		type = (unsigned long)of_data;
	else
		type = id->driver_data;

	switch (type) {
	case CS47L15:
		if (IS_ENABLED(CONFIG_MFD_CS47L15)) {
			regmap_16bit_config = &cs47l15_16bit_i2c_regmap;
			regmap_32bit_config = &cs47l15_32bit_i2c_regmap;
		}
		break;
	case CS47L35:
		if (IS_ENABLED(CONFIG_MFD_CS47L35)) {
			regmap_16bit_config = &cs47l35_16bit_i2c_regmap;
			regmap_32bit_config = &cs47l35_32bit_i2c_regmap;
		}
		break;
	case CS47L85:
	case WM1840:
		if (IS_ENABLED(CONFIG_MFD_CS47L85)) {
			regmap_16bit_config = &cs47l85_16bit_i2c_regmap;
			regmap_32bit_config = &cs47l85_32bit_i2c_regmap;
		}
		break;
	case CS47L90:
	case CS47L91:
		if (IS_ENABLED(CONFIG_MFD_CS47L90)) {
			regmap_16bit_config = &cs47l90_16bit_i2c_regmap;
			regmap_32bit_config = &cs47l90_32bit_i2c_regmap;
		}
		break;
	case CS42L92:
	case CS47L92:
	case CS47L93:
		if (IS_ENABLED(CONFIG_MFD_CS47L92)) {
			regmap_16bit_config = &cs47l92_16bit_i2c_regmap;
			regmap_32bit_config = &cs47l92_32bit_i2c_regmap;
		}
		break;
	default:
		dev_err(&i2c->dev,
			"Unknown Madera I2C device type %ld\n", type);
		return -EINVAL;
	}

	name = madera_name_from_type(type);

	if (!regmap_16bit_config) {
		/* it's polite to say which codec isn't built into the kernel */
		dev_err(&i2c->dev,
			"Kernel does not include support for %s\n", name);
		return -EINVAL;
	}

	madera = devm_kzalloc(&i2c->dev, sizeof(*madera), GFP_KERNEL);
	if (!madera)
		return -ENOMEM;


	madera->regmap = devm_regmap_init_i2c(i2c, regmap_16bit_config);
	if (IS_ERR(madera->regmap)) {
		ret = PTR_ERR(madera->regmap);
		dev_err(&i2c->dev,
			"Failed to allocate 16-bit register map: %d\n",	ret);
		return ret;
	}

	madera->regmap_32bit = devm_regmap_init_i2c(i2c, regmap_32bit_config);
	if (IS_ERR(madera->regmap_32bit)) {
		ret = PTR_ERR(madera->regmap_32bit);
		dev_err(&i2c->dev,
			"Failed to allocate 32-bit register map: %d\n", ret);
		return ret;
	}

	madera->type = type;
	madera->type_name = name;
	madera->dev = &i2c->dev;
	madera->irq = i2c->irq;

	return madera_dev_init(madera);
}