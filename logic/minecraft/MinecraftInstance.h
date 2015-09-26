#pragma once
#include "BaseInstance.h"
#include "minecraft/Mod.h"
#include <QProcess>

#include "multimc_logic_export.h"

class ModList;
class WorldList;

class MULTIMC_LOGIC_EXPORT MinecraftInstance: public BaseInstance
{
public:
	MinecraftInstance(SettingsObjectPtr globalSettings, SettingsObjectPtr settings, const QString &rootDir);
	virtual ~MinecraftInstance() {};

	/// Path to the instance's minecraft directory.
	QString minecraftRoot() const;

	//////  Mod Lists  //////
	virtual std::shared_ptr<ModList> resourcePackList() const
	{
		return nullptr;
	}
	virtual std::shared_ptr<ModList> texturePackList() const
	{
		return nullptr;
	}
	virtual std::shared_ptr<WorldList> worldList() const
	{
		return nullptr;
	}
	/// get all jar mods applicable to this instance's jar
	virtual QList<Mod> getJarMods() const
	{
		return QList<Mod>();
	}

	//FIXME: nuke?
	virtual std::shared_ptr<BaseVersionList> versionList() const override;

	/// get arguments passed to java
	QStringList javaArguments() const;

	/// get variables for launch command variable substitution/environment
	virtual QMap<QString, QString> getVariables() const override;

	/// create an environment for launching processes
	virtual QProcessEnvironment createEnvironment() override;

	/// guess log level from a line of minecraft log
	virtual MessageLevel::Enum guessLevel(const QString &line, MessageLevel::Enum level) override;

	virtual IPathMatcher::Ptr getLogFileMatcher() override;

	virtual QString getLogFileRoot() override;

	virtual QString getStatusbarDescription() override;

protected:
	QMap<QString, QString> createCensorFilterFromSession(AuthSessionPtr session);
private:
	QString prettifyTimeDuration(int64_t duration);
};

typedef std::shared_ptr<MinecraftInstance> MinecraftInstancePtr;
